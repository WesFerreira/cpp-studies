// asa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;
int main(int argc, char *argv[])
{
	App::info(argc, argv);
	Rules *rules = new Rules();

	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *fManager = new FileManager(fileName);

	if (argc > 1) {
		fManager->read();
		cout << rules->functionNames(fManager->getTempText()) <<endl;

	}
	return 0;

}