#ifndef GLOBALSCOPE_H_INCLUDED
#define GLOBALSCOPE_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "Function.h"
#include "Var.h"

// SINGLETON
class GlobalScope
{

public:
	/* Static access method. */
	static GlobalScope* getInstance();

	std::vector<Var> getVars();
	std::vector<Function> getFunctions();
	std::string getFunctionNames();

	void setVars(std::vector<Var>);
	void setFunctions(std::vector<Function>);
	void setFunctionNames(std::string);
private:
	/* Private constructor to prevent instancing. */
	GlobalScope();
	static GlobalScope* instance;

	std::vector<Var> vars;
	std::vector<Function> functions;
	std::string functionNames;
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

std::vector<Var> GlobalScope::getVars(){
	return this->vars;
}
std::vector<Function> GlobalScope::getFunctions(){
	return this->functions;
}
std::string GlobalScope::getFunctionNames() {
	return this->functionNames;
}
void GlobalScope::setVars(std::vector<Var> vars) {
	this->vars = vars;
}
void GlobalScope::setFunctions(std::vector<Function> functions) {
	this->functions = functions;
}
void GlobalScope::setFunctionNames(std::string functionNames) {
	this->functionNames = functionNames;
}
#endif