#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
/*
	Created by WesFerreira 19/11/2018
*/

#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <sstream>
#include <regex>

#include "Obj.h"

using namespace std;
class App
{
public:
	App(); ~App();

	static void info(int, char *[]);
	static void highlightText(std::string, const int);
	static vector<std::string> stringToVector(std::string);
	static bool ifExistsInText(std::string, std::string);
	static std::string removeEmptyLines(std::string);
	static vector<std::string> removeEmptyLines(vector<std::string>);

private:
	static void verboseList(vector<std::string>);
	static void verboseList(std::string, vector<std::string>);
};

App::App(){} App::~App(){}

// Shows some info when necessary.
void App::info(int argc, char *argv[]) {
	system("title AUTOMA"); // CMD Title

#ifdef INFO
	cout << MSG_DEBUG << endl;
	cout << "\{" << endl;
	cout << "  Args Number: " << argc << endl;

	// Show all args
	for (int i = 0; i < argc; i++) {
		cout << "  Arg[" << i << "]: " << argv[i] << endl;
	}

	highlightText("	FUNCTION\n", 11);
	cout << "	\{" << endl;

	cout << "		Raw Name   : " << Obj::getInstance()->function.rawName;
	cout << "		Args Number: " << Obj::getInstance()->function.args.size() << endl;
	verboseList("		", Obj::getInstance()->function.args);

	cout << "	\}" << endl << endl;
	cout << "\}" << endl << endl;
#else
	cout << MSG_INFO << endl;
#endif // !INFO
}

// HighLight a cout text.
void App::highlightText(std::string text, const int color)
{
	// Get console colors
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO con_info;
	GetConsoleScreenBufferInfo(hConsole, &con_info);
	const int saved_colors = con_info.wAttributes;

	SetConsoleTextAttribute(hConsole, color); // Set a color.
	std::cout << text.c_str(); // Print colored text.
	SetConsoleTextAttribute(hConsole, saved_colors); // Reset default color.

}

// Cast a string to vector of strings.
vector<std::string> App::stringToVector(std::string string) {
	std::stringstream ss(string.c_str());
	std::string s;
	vector<std::string>list;

	if (string.c_str() != NULL)
	{
		while (std::getline(ss, s, '\n')) {
			list.push_back(s);
		}
	}
	return list;
}

// Check if word exists inside text using native regex.
bool App::ifExistsInText(std::string find, std::string text) {
	int matchCount = 0;

	try {
		std::regex r("(\\b" + find + "\\b)");

		// This holds the first match
		std::sregex_iterator currentMatch(text.begin(), text.end(), r);

		// Used to determine if there are any more matches
		std::sregex_iterator lastMatch;

		// While the current match doesn't equal the last
		while (currentMatch != lastMatch) {
			smatch match = *currentMatch;
			currentMatch++;
			matchCount++;
		}
	}
	catch (std::regex_error& e) {
		// Syntax error in the regular expression
		std::cout << ERR_REGEX << "(\\b" + find + "\\b)" << endl;
		std::cout << e.what() << endl;
		exit;
	}

	if (matchCount > 0) {
		return true;
	}
	else {
		return false;
	}
}

// Cout list values.
void App::verboseList(vector<std::string> list) {
	for (int i = 0; list.size() > i; i++) {
		cout << "Arg[" << i << "]: " << list.at(i) << endl;
	}
}
// Cout list values with tabulation.
void App::verboseList(std::string tabulation, vector<std::string> list) {
	for (int i = 0; list.size() > i; i++) {
		cout << tabulation + "Arg[" << i << "]: " << list.at(i) << endl;
	}
}

// Remove all empty lines (\n, \t) from string.
std::string App::removeEmptyLines(std::string string) {
	string.erase(std::remove(string.begin(), string.end(), '\n'), string.end()); // Remove the \n from string.
	string.erase(std::remove(string.begin(), string.end(), '\t'), string.end()); // Remove the \t from string.
	return string;
}

// Remove all empty lines from string vector.
vector<std::string> App::removeEmptyLines(vector<std::string> stringList) {
	if (stringList.size() > 0) {
		for (int i = 0; i < stringList.size(); i++) {
			stringList.at(i) = removeEmptyLines(stringList.at(i));
			if (stringList.at(i).empty()) {
				stringList.erase(stringList.begin() + i);
				i--; // Return index if erase an item, because vectors rearrange itself.
			}
		}
	}
	stringList.shrink_to_fit(); // Dealocate memory after erases.
	return stringList;
}

#endif // !APP_H_INCLUDED
