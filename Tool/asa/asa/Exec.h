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

	void validateMeta(std::string);
	void executeCommandLines(bool);

};

Exec::Exec(){}
Exec::~Exec(){}

// Validates function call
void Exec::validateCall() {

	if (Obj::getInstance()->function.args.size() > 0) {
		// If number of args match;
		if (Obj::getInstance()->app.args.size() == Obj::getInstance()->function.args.size() + 2) { 
			executeCommandLines(true); // Execute function with args
		}
		// If number of args is less.
		else if (Obj::getInstance()->app.args.size() < Obj::getInstance()->function.args.size() + 2)
		{
			cout << ERR_MISSING_ARG << endl;
		}
		// If number of args is greater.
		else if (Obj::getInstance()->app.args.size() > Obj::getInstance()->function.args.size() + 2)
		{
			cout << ERR_MANY_ARGS << endl;
		}
	}
	else {
		executeCommandLines(false);
	}
}

// Execute commands, and input arg values if had.
void Exec::executeCommandLines(bool hasArgs) {
	if (Obj::getInstance()->function.body.empty()) {
		App::highlightText("Nothing to execute.\n", 11);
	}
	else
	{
		if (hasArgs) {
			metaWord->inputArgValues();
		}
		for (int i = 0; i < Obj::getInstance()->function.body.size(); i++) { // Foreach line in the body.
			validateMeta(Obj::getInstance()->function.body.at(i)); // Enable meta words.
		}
	}
}

// Add here all MetaWords, custom or not.
void Exec::validateMeta(std::string line) {
	if (App::ifExistsInText("cd", line)) // Enable CD to work.
	{
		metaWord->cd(line);
	}
	else
	{
		system(line.c_str());
	}
}

#endif // !EXEC_H_INCLUDED
