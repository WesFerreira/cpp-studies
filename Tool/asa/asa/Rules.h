#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include "RegularEx.h"
#include <iostream>
#include <sstream>
#include <vector>

class Rules
{
public:
	struct functions
	{
	public:
		
	private:
	} functions;

	Rules();
	~Rules();

	std::string functionName(std::string text);
	bool ifExistsInText(std::string find, std::string text);
	std::string functionBody(std::string functName, std::string text);
	std::string matchCDPatch(std::string text);
	vector<std::string> checkForArgs(std::string rawName);

	int argCount;
private:
	RegularEx *regEx = new RegularEx();
};

Rules::Rules()
{
}

Rules::~Rules()
{
}

std::string Rules::functionName(std::string text) {
	return regEx->apply(text, "(\\w+\\s?\\(.*?\\))");
}

// Check if word exists inside text;
bool Rules::ifExistsInText(std::string find, std::string text) {
	std::stringstream ss;
	ss << "(\\b" << find << "\\b)";
	regEx->apply(text, ss.str());

	if (regEx->matchCount > 0) {
		return true;
	}
	else {
		return false;
	}
}

std::string Rules::functionBody(std::string functName, std::string text) {
	std::stringstream ss;
	std::string functionStructure;

	// Match function full structure inside fullText
	ss << "(\\b" << functName << "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";
	std::string fullFunctionStruct = regEx->apply(text, ss.str());

	// Check if function has args
	vector<std::string> argList = this->checkForArgs(fullFunctionStruct);
	

	// Match function body inside function structure mateched
	return regEx->apply(fullFunctionStruct, "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");
}

// Match path after CD command
std::string Rules::matchCDPatch(std::string text) {
	return regEx->apply(text, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$");
}

vector<std::string> Rules::checkForArgs(std::string rawName) {
	// Make a vector of all args matcheds inside rawName
	vector<std::string> argList = App::stringToVector(regEx->apply(rawName, "\\$([a-zA-Z_\\x7f-\\xff][a-zA-Z0-9_\\x7f-\\xff]*)"));

	if (argList.size() > 0) {
		argCount = 0; // Reset for new query
		argCount = argList.size();
	}
	return argList;
}

#endif // !RULES_H_INCLUDED
