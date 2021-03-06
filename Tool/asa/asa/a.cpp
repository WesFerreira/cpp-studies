#include <iostream>
#include <string>
#include <time.h>

#include "pch.h"
#include "App.h"
#include "Rules.h"
#include "Exec.h"
#include "Obj.h"
#include "source/Igniter.h"

using namespace std;

int main(int argc, char *argv[])
{
	clock_t tStart = clock();
	Igniter *igniter = new Igniter();

	igniter->ignit();

	/*Rules *rules = new Rules();
	Exec *execute = new Exec();

#ifdef DEBUG
	Obj::getInstance()->app.args.push_back("a"); // App name.
	Obj::getInstance()->app.args.push_back("function"); // Function name.
	// Args
	//Obj::getInstance()->app.args.push_back("ARG1VALUE");
	//Obj::getInstance()->app.args.push_back("ARG2VALUE");

	argc = Obj::getInstance()->app.args.size();
#else
	// Sets args from arv
	for (int i = 0; i < argc; i++) {
		Obj::getInstance()->app.args.push_back(argv[i]);
	}
#endif // DEBUG

	// TODO: Let the user set the mainFile
	string fileName = "C:\\Users\\conta\\Desktop\\file.txt";
	FileManager *mainFile = new FileManager(fileName);

	Obj::getInstance()->file.globalScope = mainFile->read();
	rules->file.sequesterFunctionNames();
	rules->file.sequesterFunctions();
	rules->file.sequesterGlobalVars();

	if (argc > 1) {
			if (App::ifExistsInText(Obj::getInstance()->app.args.at(1), App::vectorToString(Obj::getInstance()->file.functionNames)))  // If function exists
			{
				// Sets args and rawName
				rules->function.checkForArgs();
				// Sets body
				rules->function.body();

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
		App::highlightText("Aura(tm) ", 11);
		App::highlightText("V-", 14);
		App::highlightText("Alpha\n", 14);
		App::highlightText("Developed with love by ", 14);
		App::highlightText("WesFerreira - https://github.com/WesFerreira \n", 112);

	}*/

	printf("Time taken: %.2fs\n", (double)(clock() - tStart) / CLOCKS_PER_SEC);
	return 0;

}