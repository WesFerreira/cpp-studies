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
	void commandLines();
private:
	Rules *rule = new Rules();
	MetaWord *metaWord = new MetaWord();

	void enableMetaWords(std::string);
};

Exec::Exec(){}
Exec::~Exec(){}

void Exec::commandLines() {
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
