#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

/*
	Created by WesFerreira 19/11/2018
*/

#include <iostream>
#include "pch.h"
using namespace std;
class App
{
public:
	App();
	~App();

	static void info(int, char *[]);

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

#endif // !APP_H_INCLUDED
