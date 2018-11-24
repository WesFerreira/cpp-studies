// asa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "Exec.h"
#include "Obj.h"
#include "FileManager.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	App::info(argc, argv);
	Rules *rules = new Rules();
	Exec *execute = new Exec();

	// TODO: Let the user set the mainFile
	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *mainFile = new FileManager(fileName);

	if (argc > 1) {
		Obj::getInstance()->file.mainText = mainFile->read();
		rules->file.functionNames(Obj::getInstance()->file.mainText);
		
		if (App::ifExistsInText(argv[1], Obj::getInstance()->file.functionNames)) { // If function exists

			// Check if function has args
			rules->function.checkForArgs(Obj::getInstance()->file.functionNames);
			// Match function body
			rules->function.body(argv[1], Obj::getInstance()->file.mainText);

			// TODO: Test if a variable with args.size is faster than get all time.
			if (Obj::getInstance()->function.args.size() > 0) {
				if (argc == Obj::getInstance()->function.args.size() + 2) { // If number of args match;
					// TODO: Execute function with args
					cout << "Exec" << endl;
				}
				else if (argc < Obj::getInstance()->function.args.size() + 2) // If number of args is less.
				{
					cout << ERR_MISSING_ARG << endl;
				}
				else if (argc > Obj::getInstance()->function.args.size() + 2) // If number of args is greater.
				{
					cout << ERR_MANY_ARGS << endl;
				}
			}
			else {
				execute->commandLines(Obj::getInstance()->function.body);

			}
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
		else
		{
			cout << "Function does not exist" << endl;
			cout << " - - - - - - - - - - - - - - - - - - - - - - - " << endl;
		}
	}
	else
	{
		App::highlightText("AUTO ", 11);
		App::highlightText("V-", 14);
		App::highlightText("Alpha\n", 14);
		App::highlightText("Developed by ", 14);
		App::highlightText("WesFerreira - https://github.com/WesFerreira \n", 112);

	}
	return 0;

}