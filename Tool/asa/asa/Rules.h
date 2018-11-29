#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <vector>
#include <boost/algorithm/string/split.hpp>

#include "RegularEx.h"
#include "Obj.h"

// RegEx rules
class Rules
{
public:
	// Nested Class
	class function : RegularEx {
	public:
		void body();
		void checkForArgs();
	private:

	} function;

	// Nested Class
	class file : RegularEx {
	public:
		void sequesterFunctionNames();
		void sequesterFunctions();
		void sequesterGlobalVars();

	private:
		void sequesterFromGlobalScope(std::string);

	} file;

	Rules(); ~Rules();
private:
};

Rules::Rules() {} Rules::~Rules() {}

///////////////////////////////////////////////// FUNCTION /////////////////////////////////////////////

// Sets the function body.
void Rules::function::body() {
	std::string functionStructure;

	// Match function full structure inside fullText
	std::string fullFunctionStruct = apply(App::vectorToString(Obj::getInstance()->file.functions),
		"(\\b" + Obj::getInstance()->app.args.at(1) + "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})");

	// Match function body inside function structure mateched
	std::string rawBody = apply(fullFunctionStruct, "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");

	Obj::getInstance()->function.body = App::removeEmptyLines(App::stringToVector(rawBody));
}

// Sets the function rawName and args if it has.
void Rules::function::checkForArgs() {

	// Reset for new query
	Obj::getInstance()->function.args.clear();
	Obj::getInstance()->function.args.shrink_to_fit();

	// Match rawName inside function names.
	Obj::getInstance()->function.rawName = apply(App::vectorToString(Obj::getInstance()->file.functionNames),
		"(\\b" + Obj::getInstance()->app.args.at(1) + "\\b\\s?\\(.*?\\))");

	// Match args inside rawName.
	Obj::getInstance()->function.args = App::stringToVector(
		apply(Obj::getInstance()->function.rawName,
			"\\$([a-zA-Z_][a-zA-Z0-9_]*)"));
}


///////////////////////////////////////////////// FILE /////////////////////////////////////////////////

// Sets all function names. (with or without args)
void Rules::file::sequesterFunctionNames() {
	Obj::getInstance()->file.functionNames = App::stringToVector(
		apply(Obj::getInstance()->file.globalScope, "(\\w+\\s?\\(.*?\\))")
	);
}

void Rules::file::sequesterFunctions() {
	for (auto name : Obj::getInstance()->file.functionNames) {
		// Isolate only the name.
		name = App::stringToVector(apply(name, "\\S[^(]*")).at(0);

		std::string matchFullFunction = "(\\b" + name + "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";

		// Store function in vector.
		Obj::getInstance()->file.functions.push_back(apply(Obj::getInstance()->file.globalScope,
			matchFullFunction));

		// Erase function of mainScope.
		sequesterFromGlobalScope(matchFullFunction);

	}
}

void Rules::file::sequesterGlobalVars() {
	std::string matchVars = "\\$([a-zA-Z_][a-zA-Z0-9_]*)";

	Obj::getInstance()->file.globalVars = App::stringToVector(apply(Obj::getInstance()->file.globalScope, matchVars));

	sequesterFromGlobalScope(matchVars);

	std::vector<std::string> v = Obj::getInstance()->file.globalVars;
}

void Rules::file::sequesterFromGlobalScope(std::string regex) {
	// Erase function of mainScope.
	Obj::getInstance()->file.globalScope = App::vectorToString(
		App::removeEmptyLines(
			App::stringToVector(
				applyReplace(
					Obj::getInstance()->file.globalScope, regex, ""))));
	// TODO: Find a better way to remove empty lines from a string (above).
}
#endif // !RULES_H_INCLUDED
