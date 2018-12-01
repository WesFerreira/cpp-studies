#ifndef MATCHER_H_INCLUDED
#define MATCHER_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "RegularEx.h"
#include "..\file\FileHolder.h"
#include "..\templates\FileAccess.h"

class Matcher : private RegularEx
{
public:
	~Matcher();
	
protected:
	std::string matchFunctions();
	std::string matchFunctionNameList();
	std::string matchVars();

	std::string matchFunctionName();
	std::string matchFunctionSignature();
	std::string matchFunctionBody();
	std::string matchFunctionArgs();

private:
	FileAccess<FileHolder> access; // Garant access to file content
	std::string fileToHandle = access.accessFileContent(*access.accessInstance());

	std::string regexToMatchFunctions = "\\*?\\w*\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";
	std::string regexToMatchFunctionNameList = "(\\w+\\s?\\(.*?\\))"; // Match function SIGNATURE list.
	std::string regexToMatchVars = "\\$([a-zA-Z_][a-zA-Z0-9_]*)"; // Match vars inside or outside parentheses. Use it inside function signature to get args.

	std::string regexToMatchFunctionName = "[a-zA-Z_][a-zA-Z0-9_]*(?![^(]*\\))"; // Match names inside signat. list.
	std::string regexToMatchFunctionSignature = ""; // Was matched before just build.
	std::string regexToMatchFunctionBody = "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})";
	std::string regexToMatchFunctionArgs = ""; // See regexToMatchVars

};
Matcher::~Matcher(){}

std::string Matcher::matchFunctions() {

}

#endif
