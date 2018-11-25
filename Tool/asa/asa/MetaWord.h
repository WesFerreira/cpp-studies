#ifndef METAWORD_H_INCLUDED
#define METAWORD_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <direct.h>

#include "RegularEx.h"

// Words that need special treatments before execute.
class MetaWord : RegularEx
{
public:
	MetaWord();
	~MetaWord();
	void cd(std::string);
	std::string arg(std::string, std::string, std::string);

private:
	std::string matchCDPatch(std::string);

};
MetaWord::MetaWord() {}
MetaWord::~MetaWord(){}

// CD don't works directly on the system, so this do the cd's work.
void MetaWord::cd(std::string line) {
	std::string path = matchCDPatch(line);

	_chdir(path.c_str()); // Go to dir

	App::highlightText("New dirPath: ", 11);
	App::highlightText(path + "\n", 14);
}

// Match path after CD command
std::string MetaWord::matchCDPatch(std::string line) {
	return App::removeEmptyLines(apply(line, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$"));
}

//
std::string MetaWord::arg(std::string line, std::string argName, std::string argValue) {
	std::string a= applyReplace(line, "\\$[a-zA-Z_][a-zA-Z0-9_]*", argValue);
	return a;
}

#endif // !METAWORD_H_INCLUDED
