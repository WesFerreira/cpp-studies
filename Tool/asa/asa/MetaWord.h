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


#include "RegularEx.h"

// Words that need special treatments before execute.
class MetaWord : RegularEx
{
public:
	MetaWord();
	~MetaWord();
	void cd(std::string);

private:
	std::string matchCDPatch(std::string);

};
MetaWord::MetaWord() {}
MetaWord::~MetaWord(){}

// CD don't works directly on the system, so this do the cd's work.
void MetaWord::cd(std::string line) {
	std::string path = matchCDPatch(line);

	if (_chdir(path.c_str())) {
		switch (errno)
		{
		case ENOENT:
			printf("Unable to locate the directory: %s\n", path);
			break;
		case EINVAL:
			printf("Invalid buffer.\n");
			break;
		default:
			printf("Unknown error.\n");
		}
	}// Go to dir
	system("dir");

	App::highlightText("New dirPath: ", 11);
	App::highlightText(path + "\n", 14);
}

// Match path after CD command
std::string MetaWord::matchCDPatch(std::string line) {
	return App::removeEmptyLines(apply(line, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$"));
}

#endif // !METAWORD_H_INCLUDED
