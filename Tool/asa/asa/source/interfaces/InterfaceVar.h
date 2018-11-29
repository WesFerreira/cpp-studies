#ifndef INTERFACEVAR_H_INCLUDED
#define INTERFACEVAR_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

class InterfaceVar
{
public:

	std::string getName() {
		return name;
	}
	std::string getValue() {
		return value;
	}

	void setValue(std::string value) {
		this->value = value;
	}

protected:
	std::string name;
	std::string value;

private:

};

#endif
