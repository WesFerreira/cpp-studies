#pragma once
#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>
#include <stdlib.h>

class FileManager
{
public:
	~FileManager();

protected:
	static std::string read(std::string);

private:

};
FileManager::~FileManager(){}

std::string FileManager::read(std::string fileName) {
	std::string line;
	std::ifstream myFileI(fileName);

	std::vector <std::string> tempText;
	int lineNumber = 0;

	if (myFileI.is_open()) {
		std::stringstream streamTempText;

		while (std::getline(myFileI, line)) {
			lineNumber++;

			tempText.insert(tempText.end(), line);

			streamTempText << tempText[lineNumber - 1] << std::endl;
		}

		myFileI.close();
		return streamTempText.str();
	}
	else {
		std::cout << "Unable to Read file." << std::endl;
		exit(-1);
	}
}
#endif // !FILEMANAGER_H_INCLUDED
