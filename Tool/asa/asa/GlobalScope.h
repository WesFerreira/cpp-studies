#ifndef GLOBALSCOPE_H_INCLUDED
#define GLOBALSCOPE_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "Function.h"

// SINGLETON
class GlobalScope
{

public:
	/* Static access method. */
	static GlobalScope* getInstance();

	std::string getVars();
	std::vector<Function> getFunctions();
	std::string getUndefined();

private:
	/* Private constructor to prevent instancing. */
	GlobalScope();
	static GlobalScope* instance;

	std::string vars;
	std::vector<Function> functions;
	std::string undefined;
};

/* Null, because instance will be initialized on demand. */
GlobalScope* GlobalScope::instance = 0;
GlobalScope* GlobalScope::getInstance()
{
	if (instance == 0)
	{
		instance = new GlobalScope();
	}

	return instance;
}
GlobalScope::GlobalScope(){}

std::string GlobalScope::getVars(){
	return this->vars;
}

std::vector<Function> GlobalScope::getFunctions(){
	return this->functions;
}

// All that is not var or function.
std::string GlobalScope::getUndefined() {
	return this->undefined;
}

#endif