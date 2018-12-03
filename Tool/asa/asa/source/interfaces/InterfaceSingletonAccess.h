#ifndef INTERFACESINGLETONACCESS_H_INCLUDED
#define INTERFACESINGLETONACCESS_H_INCLUDED
/*
	Created by WesFerreira 1/12/2018
*/

#include <iostream>

template<typename T>
class InterfaceSingletonAccess
{
public:
protected:
	T* instanceAccess() {
		return T::getInstance();
	}

private:
};
#endif
