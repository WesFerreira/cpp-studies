#ifndef EXEC_H_INCLUDED
#define EXEC_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <string>
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
	void commandLines(std::string);
private:
	Rules *rule = new Rules();
	MetaWord *word = new MetaWord();
};

Exec::Exec()
{
}

Exec::~Exec()
{
}

void Exec::commandLines(std::string commandLines) {
	std::istringstream sStream(commandLines);
	std::string line;
	while (std::getline(sStream, line)) {
		if (!line.empty()) {
			const char *cLineChar = line.c_str();
			if (rule->ifExistsInText("cd", line)) {
				word->metaCD(rule->matchCDPatch(line));
			}
			else
			{
				system(cLineChar);
			}
		}
		else
		{

		}
	}
}
#endif // !EXEC_H_INCLUDED
