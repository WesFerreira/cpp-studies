#ifndef FILEHOLDER_H_INCLUDED
#define FILEHOLDER_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>
#include <string>

#include "FileManager.h"
#include "..\interfaces\InterfaceSingletonAccess.h"
#include "..\templates\FileAccess.h"
#include "..\templates\HoldAccess.h"

class FileHolder : private FileManager
{
	friend class InterfaceSingletonAccess<FileHolder>; // Giving trust to acces the Instance.
	friend class FileAccess<FileHolder>; // Giving trust to acces the file.
	friend class HoldAccess<FileHolder>; // Giving trust to acces the Instance.

public:
protected:
private:
	static FileHolder* getInstance(); // Prevent instanciation.

	static std::string getFileContent(FileHolder&);

	std::string fileContent;

	static FileHolder* instance;
	static void hold();
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

std::string FileHolder::getFileContent(FileHolder &fh) {
	return fh.fileContent;
}

void FileHolder::hold() {
	getInstance()->fileContent = read("C:\\Users\\conta\\Desktop\\file2.txt");
	std::cout << getFileContent(*getInstance()) << std::endl;
}

#endif
