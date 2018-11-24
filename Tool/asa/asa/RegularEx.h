#ifndef REGULAREX_H_INCLUDED
#define REGULAREX_H_INCLUDED
/*
	Created by WesFerreira 22/11/2018
*/

#include <boost/regex.hpp> // To use PCRE rules
#include <iostream>
#include <sstream>

class RegularEx
{
public:
private:
protected:
	RegularEx();

	std::string apply(std::string text, std::string regex);

	int matchCount = 0;
};

RegularEx::RegularEx()
{
}

// Apply RegEx to text and returns match as string
std::string RegularEx::apply(std::string text, std::string regex) {
	matchCount = 0; // Reset count for new query.
	std::stringstream ss;
	try {
		boost::regex r(regex);

		// This holds the first match
		boost::sregex_iterator currentMatch(text.begin(),
			text.end(), r);

		// Used to determine if there are any more matches
		boost::sregex_iterator lastMatch;

		// While the current match doesn't equal the last
		while (currentMatch != lastMatch) {
			boost::smatch match = *currentMatch;
			ss << match.str() << std::endl;
			currentMatch++;
			matchCount++;
		}
	}
	catch (boost::regex_error& e) {
		// Syntax error in the regular expression
		std::cout << ERR_REGEX << regex << endl;
		std::cout << e.what() << endl;
		exit;
	}
	return ss.str();
}
#endif // !REGULAREX_H_INCLUDED
