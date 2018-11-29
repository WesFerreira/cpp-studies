#ifndef STRUCTUREBUILDER_H_INCLUDED
#define STRUCTUREBUILDER_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "GlobalScope.h"
#include "Function.h"
#include "Matcher.h"

class StructureBuilder : private Matcher
{
public:
	StructureBuilder();
	~StructureBuilder();

private:

};

StructureBuilder::StructureBuilder()
{
}

StructureBuilder::~StructureBuilder()
{
}
#endif
