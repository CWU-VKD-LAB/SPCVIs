// File Handler

#include "stdafx.h"
#include "ClassData.h"
#pragma once


class FileHandling
{
public:

	FileHandling();

	void openFile(ClassData&);
	void sortGraph(ClassData&);
	void normalizeData(ClassData &data);
	bool emptySpot(std::string);
	int getIndex(std::vector<std::string > , std::string);

};

