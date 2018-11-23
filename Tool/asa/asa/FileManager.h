#pragma once
#ifndef FILEMANAGER_H_INCLUDED
#define FILEMANAGER_H_INCLUDED

#include <fstream>
#include <sstream>
#include <vector>
#include <iostream>

class FileManager
{
public:
	int read();
	int editLine(std::vector <int>, std::vector <std::string>);
	void verbose();
	FileManager(std::string);

	std::string getTempText();
private:
	std::string fileName;
	int lineNumber = 0;
	std::vector <std::string> tempText;
};

FileManager::FileManager(std::string fileName) {
	FileManager::fileName = fileName;
}

int FileManager::read() {
	std::string line;
	std::ifstream myFileI(FileManager::fileName);

	if (myFileI.is_open()) {
		while (std::getline(myFileI, line)) {
			FileManager::lineNumber++;

			FileManager::tempText.insert(FileManager::tempText.end(), line);
		}

		myFileI.close();
	}
	else {
		std::cout << "Unable to Read file." << std::endl;
		return 0;
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
		std::cout << "Unable to Write file." << std::endl;
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

/*
* GETTERS & SETTERS
*/
std::string FileManager::getTempText() {
	std::stringstream ss;

	for (int i = 0; i < tempText.size(); i++) {
		ss << tempText[i] << std::endl;
	}

	return ss.str();
}


#endif // !FILEMANAGER_H_INCLUDED
