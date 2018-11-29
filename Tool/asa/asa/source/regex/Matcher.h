#ifndef MATCHER_H_INCLUDED
#define MATCHER_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>
#include"RegularEx.h"

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

	Matcher();
private:

	std::string regexToMatchFunctions;
	std::string regexToMatchFunctionNameList;
	std::string regexToMatchVars;

	std::string regexToMatchFunctionName;
	std::string regexToMatchFunctionSignature;
	std::string regexToMatchFunctionBody;
	std::string regexToMatchFunctionArgs;

};
Matcher::Matcher(){} Matcher::~Matcher(){}



#endif
