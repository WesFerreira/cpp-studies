#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/*
	Created by WesFerreira 19/11/2018
*/

#include <iostream>
#include <Windows.h>
#include "pch.h"
using namespace std;
class App
{
public:
	App();
	~App();

	static void info(int, char *[]);
	static void highlightText(std::string text, const int color);

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

#endif // !APP_H_INCLUDED
