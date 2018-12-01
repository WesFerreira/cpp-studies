#ifndef FILEHOLDER_H_INCLUDED
#define FILEHOLDER_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>
#include <string>

#include "FileManager.h"
#include "..\templates\FileAccess.h"

class FileHolder : private FileManager
{
public:
	friend class Igniter;	

private:
	friend class FileAccess<FileHolder>; // Giving trust to acces the file.

	static FileHolder* getInstance(); // Prevent instanciation.
	static std::string getFileContent(const FileHolder &);

	std::string fileContent;

	static FileHolder* instance;
	void hold();
};
FileHolder* FileHolder::instance = 0;
FileHolder* FileHolder::getInstance()
{
	if (instance == 0)
	{
		instance = new FileHolder();
	}

	return instance;
}

std::string FileHolder::getFileContent(const FileHolder &fileHolder) {
	return fileHolder.fileContent;
}

void FileHolder::hold() {
	getInstance()->fileContent = read("C:\\Users\\conta\\Desktop\\file2.txt");
	std::cout << getInstance()->fileContent << std::endl;
}

#endif
