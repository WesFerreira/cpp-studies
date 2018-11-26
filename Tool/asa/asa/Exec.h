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

	void enableMetaWords(std::string, std::vector<std::string>);
	void enableMetaWords(std::string);
	void executeCommandLines();
	void validateMeta(std::string);
	void executeCommandLines(std::vector<std::string>);

};

Exec::Exec(){}
Exec::~Exec(){}

// Validates function call
void Exec::validateCall() {

	// TODO: Test if a variable with args.size is faster than get all time.
	if (Obj::getInstance()->function.args.size() > 0) {
		if (Obj::getInstance()->app.args.size() == Obj::getInstance()->function.args.size() + 2) { // If number of args match;
			// TODO: Execute function with args
			executeCommandLines(Obj::getInstance()->app.args);
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
		executeCommandLines();
	}
}

void Exec::executeCommandLines(std::vector<std::string> args) {
	if (Obj::getInstance()->function.body.empty()) {
		App::highlightText("Nothing to execute.\n", 11);
	}
	else
	{
		for (int i = 0; i < Obj::getInstance()->function.body.size(); i++) {

			enableMetaWords(Obj::getInstance()->function.body.at(i), args); // Enable meta words.
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

// Add here all MetaWords, when function has arguments.
void Exec::enableMetaWords(std::string line, std::vector<std::string> args) {
	
	if (Obj::getInstance()->app.args.size() > 2) {
		std::string newLine = metaWord->arg(line, Obj::getInstance()->function.args.at(0), Obj::getInstance()->app.args.at(2));

		if (newLine.compare(line) != 0) {
			Obj::getInstance()->function.args.erase(Obj::getInstance()->function.args.begin());
			Obj::getInstance()->function.args.shrink_to_fit();

			Obj::getInstance()->app.args.erase(Obj::getInstance()->app.args.begin() + 2);
			Obj::getInstance()->app.args.shrink_to_fit();
		}
		validateMeta(newLine);
	}
	else
	{
		validateMeta(line);
	}
}
// Add here all MetaWords, custom or not.
void Exec::enableMetaWords(std::string line) {
		validateMeta(line);
}

//
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
