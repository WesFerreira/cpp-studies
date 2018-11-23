#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED

/*
	Created by WesFerreira 22/11/2018
*/
#include "RegularEx.h"
#include <iostream>
#include <string>
#include <sstream>

class Rules
{
public:
	Rules();
	~Rules();

	std::string functionNames(std::string text);
	bool ifExistsInText(std::string find, std::string text);
	std::string functionBody(std::string functName, std::string text);
	std::string matchCDPatch(std::string text);
private:
	RegularEx *regEx = new RegularEx();
};

Rules::Rules()
{
}

Rules::~Rules()
{
}

std::string Rules::functionNames(std::string text) {
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

	// Match function structure inside fullText
	ss << "(\\b" << functName << "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";

	// Match function body inside function structure mateched
	return regEx->apply(regEx->apply(text, ss.str()), "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");
}

// Match path after CD command
std::string Rules::matchCDPatch(std::string text) {
	return regEx->apply(text, "(?<=\\bcd\\b\\s)(.*)(?!\\n)$");
}

#endif // !RULES_H_INCLUDED
