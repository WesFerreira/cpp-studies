#include <iostream>
#include <string>

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "Exec.h"
#include "Obj.h"
#include "FileManager.h"

char  **g_argv;
int		g_argc;

using namespace std;

int main(int argc, char *argv[])
{
	g_argv = argv;
	g_argc = argc;

	Rules *rules = new Rules();
	Exec *execute = new Exec();

	// TODO: Let the user set the mainFile
	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *mainFile = new FileManager(fileName);

	if (argc > 1) {
		Obj::getInstance()->file.mainText = mainFile->read();
		rules->file.functionNames(Obj::getInstance()->file.mainText);
		
		if (App::ifExistsInText(argv[1], Obj::getInstance()->file.functionNames)) { // If function exists

			// Check if function has args, sets args and rawName
			rules->function.checkForArgs(argv[1], Obj::getInstance()->file.functionNames);
			// Match function body and set it
			rules->function.body(argv[1], Obj::getInstance()->file.mainText);

			execute->validateCall();
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

	App::info(argc, argv);

	return 0;

}