#ifndef STRUCTUREBUILDER_H_INCLUDED
#define STRUCTUREBUILDER_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>

#include "file/FileHolder.h"
#include "regex/Matcher.h"

class Igniter
{
public:
	Igniter();
	~Igniter();

	void ignit();
private:

};
Igniter::Igniter(){} Igniter::~Igniter(){}

void Igniter::ignit() {
	FileHolder::getInstance()->hold();
}
#endif
