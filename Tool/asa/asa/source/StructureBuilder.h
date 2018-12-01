#ifndef STRUCTUREBUILDER_H_INCLUDED
#define STRUCTUREBUILDER_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "regex/Matcher.h"
#include "structureFiles\GlobalScope.h"
#include "structureFiles\Function.h"

class StructureBuilder : private Matcher
{
public:
	StructureBuilder(); ~StructureBuilder();

	void build();

private:
	void buildGlobalScope();
};
StructureBuilder::StructureBuilder(){} StructureBuilder::~StructureBuilder(){}

void StructureBuilder::build() {
	
}
#endif
