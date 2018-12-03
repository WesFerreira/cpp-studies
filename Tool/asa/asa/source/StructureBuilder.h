#ifndef STRUCTUREBUILDER_H_INCLUDED
#define STRUCTUREBUILDER_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "../App.h"
#include "regex/Matcher.h"
#include "structureFiles\GlobalScope.h"
#include "structureFiles\Function.h"
#include "structureFiles\Arg.h"
#include "structureFiles\Var.h"

class StructureBuilder : private Matcher
{
public:
	StructureBuilder(); ~StructureBuilder();

	void build();

private:
	GlobalScope *globalScope = GlobalScope::getInstance();
};
StructureBuilder::StructureBuilder(){} StructureBuilder::~StructureBuilder(){}

void StructureBuilder::build() {

	std::vector<std::string> functions = App::removeEmptyLines(App::stringToVector(matchFunctions(), '\}'));
	std::vector<std::string> vars = App::stringToVector(matchVars(), '\n');
	std::vector<std::string> functionNames;

	std::vector<Function> functionList;
	std::vector<Var> varList;

	for (auto function : functions) {
		std::vector<Arg> argList;

		std::string signature = matchFunctionSignature(function);
		std::string name = matchFunctionName(signature);
		std::string body = matchFunctionBody(function + "}");

		std::vector<std::string> args = App::stringToVector(matchVars(signature), '\n');

		functionNames.push_back(matchFunctionName(signature));

		for (auto arg : args) {
			argList.push_back(Arg(arg));
		}
		
		functionList.push_back(Function(name, signature, body, argList));
	}

	for (auto var : vars) {
		varList.push_back(Var(var));
	}

	globalScope->setFunctionNames(App::vectorToString(functionNames));
	globalScope->setFunctions(functionList);
	globalScope->setVars(varList);
}
#endif
