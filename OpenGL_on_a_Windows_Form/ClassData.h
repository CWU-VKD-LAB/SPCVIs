///-------------------------------------------------------------------------------------------------
// file:	ClassData.h
//
// summary:	Declares the class data class
///-------------------------------------------------------------------------------------------------

#include "stdafx.h"
#include <Windows.h>
#include <GL/glu.h>
#include "glut.h"
#include <locale>         // std::locale, std::isalpha


#pragma once

//currently setup for EACH INDIVIDUAL CLASS



class ClassData // copy class before changing
{
public: 
	std::vector<std::vector<float> > classColor;
	std::vector<std::string> emptySpots;
	std::vector<float>  classTransparency;
	int classToDisplayOnTop;

	void setClassColors() {
		for (int i = 0; i < numOfClasses; i++) {
			classColor.push_back({});
			//0, (data.classNum[i] * 50) + 1, 100
			classColor[i].push_back(0);
			classColor[i].push_back((i + 1) * 50 + 1);
			classColor[i].push_back(100);
			classTransparency.push_back(255);
		}
	}
	void setClassColor(float R, float G, float B, int classnum) {
		//if(!classColor[classnum - 1].empty())
		{
			classColor[classnum-1].clear();
			classColor[classnum - 1].push_back(R);
			classColor[classnum - 1].push_back(G);
			classColor[classnum - 1].push_back(B);
		}

	}


	/// <summary>	Filename of the file. </summary>
	std::string fileName;

	/// <summary>	The values. </summary>
	std::vector<std::vector<std::string> > values;

	/// <summary>	these are actually in OpenGL.h. </summary>
	double worldWidth;
	/// <summary>	Height of the world. </summary>
	double worldHeight;

	/// <summary>	The class number. </summary>
	std::vector<int> classNum;
	/// <summary>	Number of classes. </summary>
	int numOfClasses = 0;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds class size, it is fixed at 4 for now, but should be changed when reading actual
	/// 	data.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	int classsize;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds the x max for all data. Used normalize data to the max for graphing purposes.
	///
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double xmax;
	double xscale;


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	Holds the y max for all data. Used normalize data to the max for graphing purposes.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double ymax;
	double yscale;

	/// <summary>	Width size for each graph. </summary>
	//double graphwidth;
	std::vector<double> graphwidth; 
	/// <summary>	Height size for each graph. </summary>
	//double graphheight;
	std::vector<double> graphheight;
	//for storing orthogonal information for X and Y axes for each graph 
	std::vector<double> nonOrthoX1;
	std::vector<double> nonOrthoY1;
	std::vector<double> nonOrthoX2;
	std::vector<double> nonOrthoY2;
	//defining Rectangle colors
	std::vector<double> rectR;
	std::vector<double> rectG;
	std::vector<double> rectB;
	std::vector<double> rectAndCoordx1;
	std::vector<double> rectAndCoordx2;
	std::vector<double> rectAndCoordy1;
	std::vector<double> rectAndCoordy2;
	std::vector<double> rectOrCoordx1;
	std::vector<double> rectOrCoordx2;
	std::vector<double> rectOrCoordy1;
	std::vector<double> rectOrCoordy2;
	std::vector<double> normOrx1;
	std::vector<double> normOrx2;
	std::vector<double> normOry1;
	std::vector<double> normOry2;
	std::vector<double> normAndx1;
	std::vector<double> normAndx2;
	std::vector<double> normAndy1;
	std::vector<double> normAndy2;
	std::vector<int> graphNumberOr;
	std::vector<int> graphNumberAnd;
	double temprx2;
	double temprectAndCoordy2;
	//bool seeLabels;
	bool showHideLinesVar = true; 
	bool drawAndRect = false;
	bool drawOrRect = false;
	std::string labels = "All-Axes: ";
	std::string xlabels = "X-Axes: ";
	std::string ylabels = "Y-Axes: ";

	/// <summary>	Holds different dimensions of x data. </summary>
	std::vector<std::vector<float> > xdata;
	std::vector<double> x1CoordGraph, x2CoordGraph, y1CoordGraph, y2CoordGraph;
	std::vector<float> dataTransparency;

	//Best coordinates order to rename coord labels
	std::vector<int> covScore;

	bool hdDisplay; //to display high dimension data
	int numOfGraphsPerRowHdDisplay;
	std::vector< std::vector<float>> originalXData;
	std::vector< std::vector<float>> originalYData;
	/// <summary>	Holds different dimensions of y data. </summary>
	std::vector<std::vector<float> > ydata;

	//std::vector<ClassData> classes;

	/// <summary>	The initial xclasses. </summary>
	std::vector<std::vector<float> > initialXclasses;
	/// <summary>	The initial yclasses. </summary>
	std::vector<std::vector<float> > initialYclasses;

	/// <summary>	The xclasses. </summary>
	std::vector<std::vector<float> > xclasses;
	/// <summary>	The yclasses. </summary>
	std::vector<std::vector<float> > yclasses;

	// These hold the ORIGINAL x & y coordinates for each graph position.
	// Since we're using ClassData, this might get replaced
	/// <summary>	The originalxgraphcoordinates. </summary>
	std::vector<float> originalxgraphcoordinates;
	/// <summary>	The originalygraphcoordinates. </summary>
	std::vector<float> originalygraphcoordinates;

	/// <summary>	These hold x &amp; y coordinates for each graph position. </summary>
	std::vector<float> xgraphcoordinates;
	/// <summary>	The ygraphcoordinates. </summary>
	std::vector<float> ygraphcoordinates;


	// for zooming and panning ////////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	The pan x coordinate. </summary>
	double pan_x = 0.0;
	/// <summary>	The pan y coordinate. </summary>
	double pan_y = 0.0;
	/// <summary>	The scale. </summary>
	double scale = 1.2;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>
	/// 	These are starting width and height. The world width and world height is the width after
	/// 	these starting values.
	/// </summary>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	double leftWidth = 0;
	/// <summary>	Height of the bottom. </summary>
	double bottomHeight = 0;
	/// <summary>	starting pan amount because zooming would need a different pan amount. </summary>
	int panamount = 22;

	// Color selection. Needs Updating eventually can only do 12 colors right now.
	int r[12] = { 255, 0, 0, 0, 255, 255, 0, 0, 128, 0, 128, 128 };
	int g[12] = { 0, 255, 0, 255, 0, 255, 0, 128, 0, 128, 0, 128 };
	int b[12] = { 0, 0, 255, 255, 255, 0, 128, 0, 0, 128, 128, 0 };


	void resetSomeVars() {
		numOfClasses = 0;
		classsize = 0;
		xmax = 0;
		ymax = 0;
		classColor.clear();
		leftWidth = 0;
		bottomHeight = 0;
	}



	ClassData() {};



	ClassData(std::string name)
	{
		fileName = name;
	};

	~ClassData()
	{
		// Delete as necessary.
		values.clear();
		xdata.clear();
		ydata.clear();
		initialXclasses.clear();
		initialYclasses.clear();
		xclasses.clear();
		yclasses.clear();
		originalxgraphcoordinates.clear();
		originalygraphcoordinates.clear();
		xgraphcoordinates.clear();
		ygraphcoordinates.clear();
		classNum.clear();

	}

	/* Input: Position of graph -- Creates a new empty graph */

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/// <summary>	Draw graph. </summary>
	///
	/// <remarks>	Moved from classes. </remarks>
	///
	/// <param name="x">	The x coordinate. </param>
	/// <param name="y">	The y coordinate. </param>
	////////////////////////////////////////////////////////////////////////////////////////////////////

	void drawGraph(float x, float y, float graphW, float graphH, int i)
	{
		glPushMatrix(); // Makes a new layer
		glTranslatef(x + pan_x, y + pan_y, 0.0f);
		glScalef((graphW / 2), (graphH / 2), 0.0f);
		//glRotatef(45, 1, 1, 1);
		glBegin(GL_LINE_STRIP);
		glColor3ub(0, 0, 0); // Line color
		glVertex2f(nonOrthoX1[i], nonOrthoY1[i]); //defines Y axis -1 for 90 degrees, change the first element to change angle	
		glVertex2f(-1, 1);
		glVertex2f(nonOrthoX2[i], nonOrthoY2[i]); //defines X axis, change the second element to change angle
		glEnd();
		// Draw Empty spot lines

		glBegin(GL_LINES);
		glLineWidth(4);
		if (emptySpots.size() == 1) {
			glColor3ub(r[2], g[2], b[2]);
			glVertex2f(-1 - xscale, 1.0);
			glVertex2f(-1 - xscale, 1.0 - xscale);
			glVertex2f(-1, 1 + yscale);
			glVertex2f(-1 + yscale, 1 + yscale);
		}
		else {
			for (int j = 0; j < emptySpots.size(); j++) {
				glColor3ub(r[j], g[j], b[j]);
				glVertex2f(-1 - 2 * (xscale * (j + 1)), 1.0);
				//glVertex2f(-1 - 2 * (xscale * (j + 1)), 1.0 - 2 * (xscale));
				glVertex2f(-1 - 2 * (xscale * (j + 1)), -1.0);
				glVertex2f(-1, 1 + 2 * (yscale * (j + 1)));
				//glVertex2f(-1 + 2 * (yscale), 1 + 2 * (yscale * (j + 1)));
				glVertex2f(1, 1 + 2 * (yscale * (j + 1)));
			}
		}
		glEnd();
		glPopMatrix(); // Removes the layer
	}
	
	bool is_digits(const std::string &str)
	{
		return str.find_first_not_of("0123456789") == std::string::npos;
	}
	//late entry: separate function for adding x,y labels
	void getLabels()
	{
		//for (int label = 1; label < values[0].size() - 1; label++) {
		//	if (label > 1) labels += ",";
		//	if (!is_digits(values[0][label]))
		//		labels += values[0][label];

		//	if (label % 2 != 0) {
		//		if (label > 1) xlabels += ",";
		//		if (!is_digits(values[0][label]))
		//			xlabels += values[0][label];
		//		else break;
		//	}
		//	else {
		//		if (label > 1) ylabels += ",";
		//		if (!is_digits(values[label][0]))
		//			ylabels += values[label][0];
		//		else break;
		//	}
		//}
		//stores x axis labels, but skips first and last cell
		for (int label = 1; label < values[0].size() - 1; label++)
		{
			if (label > 1) xlabels += ",";
			if (!is_digits(values[0][label]))
				xlabels += values[0][label];
			else break;
		}

		//stores y axis labels
		for (int label = 1; label < values.size(); label++)
		{
			if (label > 1) ylabels += ",";
			if (!is_digits(values[label][0]))
				ylabels += values[label][0];
			else break;
		}
	}

	void drawBitmapText(const char *string, float x, float y)
	{
		const char *c;
		glRasterPos2f(x, y);

		int i = 0;
		for (c = string; *c != NULL; c++)
		{
			if (i < strlen(string))
			{
				glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, *c);
			}
			else
			{
				break;
			}
			i++;
		}

	}

	void drawLabels()
	{
		glColor3f(0, 0, 0);
		//drawBitmapText(xlabels.c_str(), .8*worldWidth, .98*worldHeight);
		//drawBitmapText(ylabels.c_str(), .05*worldWidth, .05*worldHeight);
		//Prints empty spots as list in top right of window. If empty string prints """ (empty string)" instead of nothing.
		if (emptySpots.size() > 0) {
			std::string s = "Empty Spot Values: ";

			for (int i = 0; i < emptySpots.size() - 1; i++) {
				if (emptySpots[i] == "") {
					s.append("\"\"(empty string)");
					s.append(",");
				}
				else {
					s.append(emptySpots[i]);
					s.append(", ");
				}
			}
			if (emptySpots[emptySpots.size() - 1] == "") {
				s.append("\"\" (empty string)");
			}
			else {
				s.append(emptySpots[emptySpots.size() - 1]);
			}
			char* cstr = new char[s.length() + 1];
			std::strcpy(cstr, s.c_str());
			drawBitmapText(cstr, .02 * worldWidth, .02 * worldHeight);
		}
	}
};







