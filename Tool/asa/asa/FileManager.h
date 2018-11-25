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
	std::string read();
	int editLine(std::vector <int>, std::vector <std::string>);
	void verbose();

	FileManager(std::string);
	~FileManager();

private:
	std::string fileName;
	int lineNumber = 0;
	std::vector <std::string> tempText;
};

FileManager::FileManager(std::string fileName) {
	FileManager::fileName = fileName;
}
FileManager::~FileManager(){}

std::string FileManager::read() {
	std::string line;
	std::ifstream myFileI(FileManager::fileName);

	if (myFileI.is_open()) {
		std::stringstream streamTempText;

		while (std::getline(myFileI, line)) {
			FileManager::lineNumber++;

			FileManager::tempText.insert(FileManager::tempText.end(), line);

			streamTempText << FileManager::tempText[lineNumber - 1] << std::endl;
		}

		myFileI.close();
		return streamTempText.str();
	}
	else {
		std::cout << "Unable to Read file." << std::endl;
		exit(-1);
	}
}

int FileManager::editLine(std::vector <int> line, std::vector <std::string> text) {
	std::ofstream myFileO;

	myFileO.open(FileManager::fileName);
	if (myFileO.is_open()) {

		for (int v = 0; v < line.size(); v++) {
			FileManager::tempText.at(line.at(v)) = text.at(v);
		}
		for (int i = 0; i < FileManager::lineNumber; i++) {
			myFileO << FileManager::tempText.at(i) << '\n';
		}
		myFileO.close();
	}
	else
	{
		std::cout << "Unable to Write file: " << fileName << std::endl;
		return 0;
	}
}

void FileManager::verbose() {
	if (tempText.size() > 0) {
		for (int i = 0; i < tempText.size(); i++) {
			std::cout << tempText[i] << endl;
		}
	}
	else {
		cout << ERR_NOTHING_TO_SHOW << endl;
		exit;
	}
}
#endif // !FILEMANAGER_H_INCLUDED
