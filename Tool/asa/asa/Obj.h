#ifndef OBJ_H_INCLUDED
#define OBJ_H_INCLUDED
/*
	Created by WesFerreira 23/11/2018
*/

#include <iostream>
#include <vector>

// SINGLETON
class Obj
{
private:
	/* Here will be the instance stored. */
	static Obj* instance;

	/* Private constructor to prevent instancing. */
	Obj() {};

public:
	/* Static access method. */
	static Obj* getInstance();

	// *OBJECT
	struct function
	{
		std::string body; // Function name body.
		std::vector<std::string> args; // Function args.

	} function;

	// *OBJECT
	struct file
	{
		std::string mainText;
		std::string functionNames; // Function names. (with or without args)
	} file;
};

/* Null, because instance will be initialized on demand. */
Obj* Obj::instance = 0;

Obj* Obj::getInstance()
{
	if (instance == 0)
	{
		instance = new Obj();
	}

	return instance;
}

#endif // !OBJ_H_INCLUDED
