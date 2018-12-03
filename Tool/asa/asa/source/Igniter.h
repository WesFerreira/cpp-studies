#ifndef IGNITER_H_INCLUDED
#define IGNITER_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>

#include "structureFiles/GlobalScope.h"
#include "file/FileHolder.h"
#include "StructureBuilder.h"
#include "regex/Matcher.h"
#include "templates/HoldAccess.h"


class Igniter
{
public:
	Igniter();
	~Igniter();

	void ignit();
private:
	HoldAccess<FileHolder> access;

	StructureBuilder *sBuilder = new StructureBuilder();

	GlobalScope *globalScope = GlobalScope::getInstance();

};
Igniter::Igniter(){} Igniter::~Igniter(){}

void Igniter::ignit() {
	access.hold();
	sBuilder->build();
}
#endif
