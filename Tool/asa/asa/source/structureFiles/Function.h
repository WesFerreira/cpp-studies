#ifndef FUNCTION_H_INCLUDED
#define FUNCTION_H_INCLUDED
/*
	Created by WesFerreira 29/11/2018
*/

#include <iostream>
#include <vector>

#include "Arg.h"

class Function
{
public:
	Function(std::string, std::string, std::string, std::vector<Arg>);
	~Function();

	std::string getName();
	std::string getSignature();
	std::string getBody();
	std::vector<Arg> getArgs();

private:
	std::string name;
	std::string signature;
	std::string body;
	std::vector<Arg> args;

};

Function::Function(std::string name, std::string signature, std::string body, std::vector<Arg> args)
{
	this->name = name;
	this->signature = signature;
	this->body = body;
	this->args = args;
}

Function::~Function()
{
}

std::string Function::getName() {
	return this->name;
}

std::string Function::getSignature() {
	return this->signature;
}

std::string Function::getBody() {
	return this->body;
}

std::vector<Arg> Function::getArgs() {
	return this->args;
}

#endif