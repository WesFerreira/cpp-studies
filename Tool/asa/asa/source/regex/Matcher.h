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
protected:
	std::string matchFunctions();
	std::string matchVars();
	std::string matchVars(std::string); // Reused to match all vars in all scopes.

	std::string matchFunctionSignature(std::string);
	std::string matchFunctionName(std::string);
	std::string matchFunctionBody(std::string);

private:
	FileAccess<FileHolder> access; // Garant access to file content
	std::string fileContentWithoutFunction;

	std::string regexToMatchFunctions = "\\*?\\w*\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";
	std::string regexToMatchVars = "\\$([a-zA-Z_][a-zA-Z0-9_]*)";

	std::string regexToMatchFunctionSignature = "(\\w+\\s?\\(.*?\\))";
	std::string regexToMatchFunctionName = "[a-zA-Z_][a-zA-Z0-9_]*(?![^(]*\\))(?![^{]*\\})";
	std::string regexToMatchFunctionBody = "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})";

};

std::string Matcher::matchFunctions() {
	std::string fileContentToHandle = access.fileContentAccess(*access.instanceAccess());
	std::string functions = apply(fileContentToHandle, regexToMatchFunctions);

	fileContentWithoutFunction = eraseMatch(fileContentToHandle, regexToMatchFunctions);
	return functions;
}

std::string Matcher::matchVars() {
	return apply(fileContentWithoutFunction, regexToMatchVars);
}

std::string Matcher::matchVars(std::string scope) {
	return apply(scope, regexToMatchVars);
}

std::string Matcher::matchFunctionSignature(std::string function) {
	return apply(function, regexToMatchFunctionSignature);
}

std::string Matcher::matchFunctionName(std::string function) {
	return apply(function, regexToMatchFunctionName);
}

std::string Matcher::matchFunctionBody(std::string function) {
	return apply(function, regexToMatchFunctionBody);
}

#endif
