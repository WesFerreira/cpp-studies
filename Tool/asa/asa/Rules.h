#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED

/*
	Created by WesFerreira 22/11/2018
*/
#include "RegularEx.h"
#include <iostream>
#include <string>

class Rules
{
public:
	Rules();
	~Rules();

	std::string functionNames(std::string text);
private:
	RegularEx *regex = new RegularEx();
};

Rules::Rules()
{
}

Rules::~Rules()
{
	delete regex;
}

std::string Rules::functionNames(std::string text) {
	return regex->apply(text, "(\\w+\\s?\\(.*?\\))");
}
#endif // !RULES_H_INCLUDED
