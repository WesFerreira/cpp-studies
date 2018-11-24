#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
/*
	Created by WesFerreira 19/11/2018
*/

#include <iostream>
#include <Windows.h>
#include <vector>
#include <sstream>
#include <regex>

using namespace std;
class App
{
public:
	App();
	~App();

	static void info(int, char *[]);
	static void highlightText(std::string, const int);
	static vector<std::string> stringToVector(std::string);
	static bool ifExistsInText(std::string, std::string);
private:

};

App::App()
{
}
App::~App()
{
}

void App::info(int argc, char *argv[]) {
	system("title A.S.A."); // CMD Title
	//TODO: Add powershell title, after verify what is running.

#ifdef DEBUG
	cout << MSG_DEBUG << endl;
	cout << "\{" << endl;
	cout << "  Args Number: " << argc << endl;

	// Show all args
	for (int i = 0; argc > i; i++) {
		cout << "  Arg[" << i << "]: " << argv[i] << endl;
	}
	cout << "\}" << endl << endl;
#else
	cout << MSG_INFO << endl;
#endif // !DEBUG
}

// HighLight a cout text
void App:: highlightText(std::string text, const int color)
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
	std::stringstream ss;
	ss << "(\\b" << find << "\\b)";

	try {
		std::regex r(ss.str());

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
		std::cout << ERR_REGEX << ss.str() << endl;
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

#endif // !APP_H_INCLUDED
