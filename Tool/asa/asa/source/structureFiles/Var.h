#ifndef VAR_H_INCLUDED
#define VAR_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "..\interfaces\InterfaceVar.h"

class Var : public InterfaceVar
{
public:
	Var (std::string name);
	~Var ();

private:

};

Var::Var(std::string name) {
	this->name = name;
}
Var ::~Var (){}

#endif
