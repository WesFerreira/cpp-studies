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
	std::string matchFunctions(std::string textToApplyRegex);
	std::string matchFunctionNameList(std::string textToApplyRegex);
	std::string matchVars(std::string textToApplyRegex);

	std::string matchFunctionName(std::string textToApplyRegex);
	std::string matchFunctionSignature(std::string textToApplyRegex);
	std::string matchFunctionBody(std::string textToApplyRegex);
	std::string matchFunctionArgs(std::string textToApplyRegex);

private:

	FileAccess<FileHolder> access; // Garant access to file content
	std::string fileToHandle = access.accessFileContent(*access.accessHolderInstance());

	std::string regexToMatchFunctions;
	std::string regexToMatchFunctionNameList;
	std::string regexToMatchVars;

	std::string regexToMatchFunctionName;
	std::string regexToMatchFunctionSignature;
	std::string regexToMatchFunctionBody;
	std::string regexToMatchFunctionArgs;

};
Matcher::~Matcher(){}

#endif
