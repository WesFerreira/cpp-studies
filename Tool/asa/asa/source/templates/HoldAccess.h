#ifndef HOLDACCESS_H_INCLUDED
#define HOLDACCESS_H_INCLUDED
/*
	Created by WesFerreira 1/12/2018
*/

#include <iostream>

#include "..\interfaces\InterfaceSingletonAccess.h"

// PassKey Iidiom (Pattern)
template<typename T> 
class HoldAccess : public InterfaceSingletonAccess <T>
{
public:
private:
	friend class Igniter;

	HoldAccess(){}

	void hold() {
		T::hold();
	}
};
#endif
