#ifndef METAWORD_H_INCLUDED
#define METAWORD_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <direct.h>
#include <errno.h>  

#include "source/regex/RegularEx.h"

// Words that need special treatments before execute.
class MetaWord : RegularEx
{
public:
	MetaWord(); ~MetaWord();

	void cd(std::string);
	void inputArgValues();

private:
	std::string matchCDPatch(std::string);
};

MetaWord::MetaWord() {} MetaWord::~MetaWord(){}

// CD don't works directly on the system, so this do the cd's work.
void MetaWord::cd(std::string line) {
	std::string path = matchCDPatch(line);

	if (_chdir(path.c_str()))
	{
		switch (errno)
		{
		case ENOENT:
			std::cout << "Unable to locate the directory: " + path << endl;
			exit(EXIT_FAILURE);
			break;
		case EINVAL:
			printf("Your directory has a unusual character.\n");
			exit(EXIT_FAILURE);
			break;
		default:
			printf("Unknown error on trying to change directory.\n");
			exit(EXIT_FAILURE);
		}
	}
	App::highlightText("New dirPath: ", 11);
	App::highlightText(path + "\n", 14);
}

// Match path after CD command
std::string MetaWord::matchCDPatch(std::string line) {
	return App::removeEmptyLines(apply(line, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$"));
}

// Replace arg name by arg value in all body.
void MetaWord::inputArgValues() {
	std::string body = App::vectorToString(Obj::getInstance()->function.body);

	for (int i = 0; i < Obj::getInstance()->function.args.size(); i++) { // Foreach function args
		// Replace the argName for argValue in all body, in case of argName reuses.
		body = applyReplace(body, "\\" + Obj::getInstance()->function.args.at(i), Obj::getInstance()->app.args.at(i + 2));
	}
	Obj::getInstance()->function.body = App::stringToVector(body, '\n');
}

#endif // !METAWORD_H_INCLUDED
