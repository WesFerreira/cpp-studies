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

class Rules : RegularEx
{
public:
	// Nested Class
	class function : RegularEx {
	public:
		std::string body(std::string, std::string);
		void checkForArgs(std::string);

	private:
	} function;

	// Nested Class
	class file : RegularEx {
	friend class Rules;
	public:
		std::string functionNames(std::string);

	private:
	} file;

private:
};

///////////////////////////////////////////////// FUNCTION /////////////////////////////////////////////////



std::string Rules::function::body(std::string functName, std::string mainText) {
	std::stringstream ss;
	std::string functionStructure;

	// Match function full structure inside fullText
	ss << "(\\b" << functName << "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})";
	std::string fullFunctionStruct = apply(mainText, ss.str());


	// Match function body inside function structure mateched
	return apply(fullFunctionStruct, "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");
}

void Rules::function::checkForArgs(std::string rawName) {
	Obj::getInstance()->function.args.clear(); // Reset for new query
	// Make a vector of all args matcheds inside rawName
	Obj::getInstance()->function.args = App::stringToVector(apply(rawName, "\\$([a-zA-Z_][a-zA-Z0-9_]*)"));
}



///////////////////////////////////////////////// FILE /////////////////////////////////////////////////

// Match all function names in the file. (with or without args)
std::string Rules::file::functionNames(std::string mainText) {
	return apply(mainText, "(\\w+\\s?\\(.*?\\))");
}



///////////////////////////////////////////////// GENERAL /////////////////////////////////////////////////


#endif // !RULES_H_INCLUDED
