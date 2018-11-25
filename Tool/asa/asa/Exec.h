#ifndef EXEC_H_INCLUDED
#define EXEC_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <cstdlib>

#include "Rules.h"
#include "MetaWord.h"

extern char **g_argv;
extern int	  g_argc;

using namespace std;
class Exec
{
public:
	Exec();
	~Exec();
	void validateCall();
private:
	Rules *rule = new Rules();
	MetaWord *metaWord = new MetaWord();

	void enableMetaWords(std::string);
	void executeCommandLines();
	void executeCommandLines(char **args);

};

Exec::Exec(){}
Exec::~Exec(){}

// Validates function call
void Exec::validateCall() {

	// TODO: Test if a variable with args.size is faster than get all time.
	if (Obj::getInstance()->function.args.size() > 0) {
		if (g_argc == Obj::getInstance()->function.args.size() + 2) { // If number of args match;
			// TODO: Execute function with args
			executeCommandLines(g_argv);
		}
		// If number of args is less.
		else if (g_argc < Obj::getInstance()->function.args.size() + 2)
		{
			cout << ERR_MISSING_ARG << endl;
		}
		// If number of args is greater.
		else if (g_argc > Obj::getInstance()->function.args.size() + 2)
		{
			cout << ERR_MANY_ARGS << endl;
		}
	}
	else {
		executeCommandLines();
	}
}

void Exec::executeCommandLines(char **args) {
	if (Obj::getInstance()->function.body.empty()) {
		App::highlightText("Nothing to execute.\n", 11);
	}
	else
	{
		for (int i = 0; i < Obj::getInstance()->function.body.size(); i++) {
			enableMetaWords(Obj::getInstance()->function.body.at(i)); // Enable meta words.
		}
	}
}

void Exec::executeCommandLines() {
	if (Obj::getInstance()->function.body.empty()) {
		App::highlightText("Nothing to execute.\n", 11);
	}
	else
	{
		for (int i = 0; i < Obj::getInstance()->function.body.size(); i++) {
			enableMetaWords(Obj::getInstance()->function.body.at(i)); // Enable meta words.
		}
	}
}

// Add here all MetaWords, custom or not.
void Exec::enableMetaWords(std::string line) {
	const char *cLineChar = line.c_str();

	if (App::ifExistsInText("cd", line)) // Enable CD to work.
	{
		metaWord->cd(line);
	}
	else
	{
		system(cLineChar);
	}
}


#endif // !EXEC_H_INCLUDED
