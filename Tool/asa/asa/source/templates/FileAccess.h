#ifndef FILEACCESS_H_INCLUDED
#define FILEACCESS_H_INCLUDED
/*
	Created by WesFerreira 30/11/2018
*/

#include <iostream>

// PassKey Iidiom (Pattern)
template <typename T> class FileAccess
{
public:
private:
	friend class Matcher;

	// Only friends can to access these methods.
	FileAccess() {}

	std::string accessFileContent(const T &fHolder) {
		return T::getFileContent(fHolder);
	}

	T* accessHolderInstance() {
		return T::getInstance();
	}

};
#endif
