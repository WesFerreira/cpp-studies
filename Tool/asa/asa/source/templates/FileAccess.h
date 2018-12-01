#ifndef FILEACCESS_H_INCLUDED
#define FILEACCESS_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>

#include "..\interfaces\InterfaceSingletonAccess.h"

// PassKey Iidiom (Pattern)
template <typename T> 
class FileAccess : private InterfaceSingletonAccess <T>
{
public:
private:
	friend class Matcher;

	// Only friends can to access these methods.
	FileAccess() {}

	std::string accessFileContent(const T &fHolder) {
		return T::getFileContent(fHolder);
	}


};
#endif
