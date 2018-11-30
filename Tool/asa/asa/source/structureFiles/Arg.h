#ifndef ARG_H_INCLUDED
#define ARG_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "..\interfaces\InterfaceVar.h"

class Arg : public InterfaceVar
{
public:
	Arg(std::string name); // Test 
	~Arg();

private:

};

Arg::Arg(std::string name) {
	this->name = name;
}
Arg::~Arg(){}

#endif
