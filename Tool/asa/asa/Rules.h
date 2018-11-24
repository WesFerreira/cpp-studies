#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include "RegularEx.h"
#include "Obj.h"
#include <iostream>
#include <sstream>
#include <vector>

// RegEx rules
class Rules : RegularEx
{
public:
	// Nested Class
	class function : RegularEx {
	public:
		void body(std::string, std::string);
		void checkForArgs(std::string);

	private:
	} function;

	// Nested Class
	class file : RegularEx {
	friend class Rules;
	public:
		void functionNames(std::string);

	private:
	} file;

private:
};

///////////////////////////////////////////////// FUNCTION /////////////////////////////////////////////////

// Sets the function body.
void Rules::function::body(std::string functName, std::string mainText) {
	std::stringstream ss;
	std::string functionStructure;

	// Match function full structure inside fullText
	ss << "(\\b" << functName << "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";
	std::string fullFunctionStruct = apply(mainText, ss.str());

	// Match function body inside function structure mateched
	Obj::getInstance()->function.body = apply(fullFunctionStruct, "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");
}
// Sets the function args if it has.
void Rules::function::checkForArgs(std::string functionNames) {
	Obj::getInstance()->function.args.clear(); // Reset for new query

	// Make a vector of all args matcheds inside functionNames
	Obj::getInstance()->function.args = App::stringToVector(apply(functionNames, "\\$([a-zA-Z_][a-zA-Z0-9_]*)"));
}



///////////////////////////////////////////////// FILE /////////////////////////////////////////////////

// Sets all function names. (with or without args)
void Rules::file::functionNames(std::string mainText) {
	Obj::getInstance()->file.functionNames = apply(mainText, "(\\w+\\s?\\(.*?\\))");
}



///////////////////////////////////////////////// GENERAL /////////////////////////////////////////////////


#endif // !RULES_H_INCLUDED
