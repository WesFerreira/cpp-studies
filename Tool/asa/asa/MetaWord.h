#ifndef METAWORD_H_INCLUDED
#define METAWORD_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <string>
#include <direct.h>
#include <algorithm>
#include "RegularEx.h"

class MetaWord : RegularEx
{
public:
	MetaWord();
	~MetaWord();
	void metaCD(std::string);
	std::string matchCDPatch(std::string);
private:

};

MetaWord::MetaWord()
{
}

MetaWord::~MetaWord()
{
}

void MetaWord::metaCD(std::string path) {
	path.erase(std::remove(path.begin(), path.end(), '\n'), path.end());
	_chdir(path.c_str());

	App::highlightText("New dirPath: ", 11);
	App::highlightText(path + "\n", 14);
}


// Match path after CD command
std::string MetaWord::matchCDPatch(std::string text) {
	return apply(text, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$");
}

#endif // !METAWORD_H_INCLUDED
