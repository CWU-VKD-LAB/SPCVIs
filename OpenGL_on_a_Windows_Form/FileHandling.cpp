///-------------------------------------------------------------------------------------------------
// file:	FileHandling.cpp
//
// summary:	Implements the file handling class
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include "FileHandling.h"
#include <set>
#include <utility>
#include <iterator>


FileHandling::FileHandling() {}

// Input: Contents of input.csv -- Opens the file and reads the values into matrix values


void FileHandling::openFile(ClassData& data)
{
	using namespace std;
	ifstream myFile;
	string line;

	std::cout << "Trying to load file: " << data.fileName << "\n";
	myFile.open(data.fileName);											// Open the file

	if (myFile.is_open()) {												/* Valid File: Begin reading data form the file */
		vector<std::string> columns;

		while (getline(myFile, line)) {									/* While the file has more data */
			istringstream cell(line);
			string distance;
			while (getline(cell, distance, ',')) {
				columns.push_back(distance);
			}
			data.values.push_back(columns);								// Store data
			columns.clear();
		}

	}
	myFile.close();
}

// Input: Contents of input.csv -- Splits the values into x and y coords


void FileHandling::sortGraph(ClassData& data)
{
	std::vector<float> xdatatemp;
	std::vector<float> ydatatemp;
	float xCoord = 0;
	float yCoord = 0;

	data.getLabels();

	for (int i = 1; i < (data.values.size()); i++)					// OLD: for (int i = 1; i < (data.values.size() - 1); i++)
	{																	// Columns
		int nodeClass =
			stoi(data.values[i][(data.values[0].size() - 1)]);          // Get the class of the node
		if (nodeClass > data.numOfClasses)                              // Get the highest class number
			data.numOfClasses = nodeClass;
		data.classNum.push_back(nodeClass);                             // Add to vector of class numbers

		std::set<std::string> emptyvalues;
		for (int j = 1; j < (data.values[i].size() - 1); j++)			// Rows
		{
			if (xdatatemp.size() <= ydatatemp.size())					// Get X-coords
			{
				if (FileHandling::emptySpot(data.values[i][j])) {
					int index = FileHandling::getIndex(data.emptySpots, data.values[i][j]);
					if (index != -1) {
						xCoord = -(index + 1);
					}
					else {
						data.emptySpots.push_back(data.values[i][j]);
						xCoord = -1*((int)data.emptySpots.size() + 1);
					}
					xdatatemp.push_back(xCoord);
				}
				else{
					xCoord = stof(data.values[i][j]);
					xdatatemp.push_back(xCoord);
					if (xCoord > data.xmax)
						data.xmax = xCoord;
				}
			}
			else
			{
				// Get y coords
				if (FileHandling::emptySpot(data.values[i][j])) {
					int index = FileHandling::getIndex(data.emptySpots, data.values[i][j]);
					if (index != -1) {
						yCoord = -(index + 1);
					}
					else {
						data.emptySpots.push_back(data.values[i][j]);
						yCoord = -1*((int)data.emptySpots.size() + 1);
					}
					ydatatemp.push_back(yCoord);
				}
				else {
					yCoord = stof(data.values[i][j]);
					ydatatemp.push_back(yCoord);
					if (yCoord > data.ymax)
						data.ymax = yCoord;
				}
			}
		}
		if (xdatatemp.size() != ydatatemp.size())						// Duplicate last pair if odd # of columns
		{
			ydatatemp.push_back(xCoord);
			if (yCoord > data.ymax)  // Get y-max
				data.ymax = yCoord;
		}
		data.xdata.push_back(xdatatemp);
		data.dataTransparency.push_back(255);
		data.originalXData.push_back(xdatatemp); // Add line plot coords
		data.ydata.push_back(ydatatemp);
		data.originalYData.push_back(ydatatemp);
		xdatatemp.clear();                                              // Clear for the next plot line
		ydatatemp.clear();



	}
}

void FileHandling::normalizeData(ClassData& data)
{
	// Y Normalization
	std::vector<float> minYcol;
	std::vector<float> maxYcol;
	std::vector<float> temp;

	std::vector<std::vector<float> > convertedValues; // NEW


	float min = 0;
	float max = 0;

	for (int j = 0; j < data.ydata[0].size(); j++) {                                               // Gets the min and max of every column
		min = data.ydata[0][j];
		for (int i = 0; i < data.ydata.size(); i++) {
			if (data.ydata[i][j] > max) {
				max = data.ydata[i][j];
			}
			if (data.ydata[i][j] < min && data.ydata[i][j] >= 0) {
				min = data.ydata[i][j];
			}
		}
		if (min == max)   // This is used when entire column is of same values, the normalized value is 0.5 (chosen arbitrarily)
			min = 0;
		minYcol.push_back(min);
		maxYcol.push_back(max);
		max = 0;

	}



	for (int i = 0; i < data.ydata.size(); i++) {                                                  // Normalize the data from 0 - 1
		for (int j = 0; j < data.ydata[0].size(); j++) {
			float original = data.ydata[i][j];
			float currentMin = minYcol[j];
			float currentMax = maxYcol[j];
			float converted;
			float scale = (currentMax - currentMin) * 0.20/currentMax;
			data.yscale = scale / (int)data.emptySpots.size();
			currentMax = currentMax + (currentMax-currentMin)/10;
			if (data.ydata[i][j] < 0) {
				if (data.emptySpots.size() == 1) {
					converted = -data.yscale / 2;
				}
				else {
					converted = original * data.yscale;
				}
			}
			else {
				converted = (original - currentMin) / (currentMax - currentMin);
			}

			temp.push_back(converted);
		}
		convertedValues.push_back(temp);
		temp.clear();
	}
	data.ydata.clear();
	data.ydata = convertedValues;																	// Fill ydata coordinates with normalized data  
	data.originalYData = convertedValues;

	convertedValues.clear();
	//data.xmax = data.ydata[0].size();																// Change xMax and yMax to normalized data
	data.ymax = 1;

	// X Normalization after this point
	std::vector<float> minXcol;
	std::vector<float> maxXcol;
	temp.clear();

	convertedValues.clear();


	min = 0;
	max = 0;

	for (int j = 0; j < data.xdata[0].size(); j++) {                                               // Gets the min and max of every column
		min = data.xdata[0][j];
		for (int i = 0; i < data.xdata.size(); i++) {
			if (data.xdata[i][j] > max) {
				max = data.xdata[i][j];
			}
			if (data.xdata[i][j] < min && data.xdata[i][j] >= 0) {
				min = data.xdata[i][j];
			}
		}
		if (min == max)   //This is used when entire column is of same values, the normalized value is 0.5 (chosen arbitrarily)
			min = 0;
		minXcol.push_back(min);
		maxXcol.push_back(max);
		max = 0;
	}


	for (int i = 0; i < data.xdata.size(); i++) {                                                  // Normalize the data from 0 - 1
		for (int j = 0; j < data.xdata[0].size(); j++) {
			float original = data.xdata[i][j];
			float currentMin = minXcol[j];
			float currentMax = maxXcol[j];
			float converted;
			float scale = (currentMax - currentMin) * 0.20/currentMax;
			data.xscale = scale / (int)data.emptySpots.size();
			currentMax = currentMax + (currentMax-currentMin)/10;
			if (data.xdata[i][j] < 0) {
				if (data.emptySpots.size() == 1) {
					converted = -data.xscale / 2;
				}
				else {
					converted = original * data.xscale;
				}
			}
			else {
				converted = (original - currentMin) / (currentMax - currentMin);
			}

			temp.push_back(converted);
		}
		convertedValues.push_back(temp);
		temp.clear();
	}
	data.xdata.clear();
	data.xdata = convertedValues;																	// Fill ydata coordinates with normalized data  
	data.originalXData = convertedValues;
	convertedValues.clear();
	//data.xmax = data.ydata[0].size();																// Change xMax and yMax to normalized data
	data.xmax = 1;
}


/// <summary>
/// Determines whether or not the inputed string is an empty spot in the data.
/// </summary>
/// <param name="ent">String in question</param>
/// <returns>True if string is not a number, False string is a number</returns>
bool FileHandling::emptySpot(std::string ent) {
	float temp;
	try {
		temp = stof(ent);
	}
	catch (const std::invalid_argument& ia) {
		return true;
	}
	return false;
}

/// <summary>
/// Finds the index of a string in a list of strings.
/// </summary>
/// <param name="l">List of strings</param>
/// <param name="s">String in question</param>
/// <returns>Returns the index of the string if found. If not found returns -1.</returns>
int FileHandling::getIndex(std::vector<std::string> l, std::string s) {
	auto it = find(l.begin(), l.end(), s);

	if (it != l.end()) {
		int index = it - l.begin();
		return index;
	}
	else {
		return -1;
	}
}