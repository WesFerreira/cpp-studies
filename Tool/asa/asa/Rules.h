#ifndef RULES_H_INCLUDED
#define RULES_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <iostream>
#include <vector>

#include "RegularEx.h"
#include "Obj.h"

// RegEx rules
class Rules
{
public:
	// Nested Class
	class function : RegularEx {
	public:
		void body(std::string, std::string);
		void checkForArgs(std::string, std::string);
	private:
	} function;

	// Nested Class
	class file : RegularEx {
	friend class Rules;
	public:
		void functionNames(std::string);

	private:
	} file;

	Rules();
	~Rules();
private:
};

Rules::Rules(){}
Rules::~Rules(){}

///////////////////////////////////////////////// FUNCTION /////////////////////////////////////////////////

// Sets the function body.
void Rules::function::body(std::string functName, std::string mainText) {
	std::string functionStructure;

	// Match function full structure inside fullText
	std::string fullFunctionStruct = apply(mainText, "(\\b" + functName + "\\b)\\(.*?\\)\\s*({(?:{[^{}]*}|.)*?})");

	// Match function body inside function structure mateched
	std::string rawBody = apply(fullFunctionStruct, "(?<=\\{)((?:.*?\\r?\\n?)*)(?=\\})");

	Obj::getInstance()->function.body = App::removeEmptyLines(App::stringToVector(rawBody));
}
// Sets the function rawName and args if it has.
void Rules::function::checkForArgs(std::string name, std::string functionNames) {
	Obj::getInstance()->function.args.clear(); // Reset for new query

	// Match rawName inside function names.
	Obj::getInstance()->function.rawName = apply(functionNames, "(\\b" + name + "\\b\\s?\\(.*?\\))");

	// Match args inside rawName.
	Obj::getInstance()->function.args = App::stringToVector(
		apply(Obj::getInstance()->function.rawName,
		"\\$([a-zA-Z_][a-zA-Z0-9_]*)")
	);
}



///////////////////////////////////////////////// FILE /////////////////////////////////////////////////

// Sets all function names. (with or without args)
void Rules::file::functionNames(std::string mainText) {
	Obj::getInstance()->file.functionNames = apply(mainText, "(\\w+\\s?\\(.*?\\))");
}



///////////////////////////////////////////////// GENERAL /////////////////////////////////////////////////


#endif // !RULES_H_INCLUDED
