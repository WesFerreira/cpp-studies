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
protected:
	std::string apply(std::string, std::string);
	std::string applyReplace(std::string, std::string, std::string);

	int matchCount = 0;

private:
	std::string formatPathForRegex(const std::string &s);

};

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

// Apply RegEx to text, replace match, and returns as string
std::string RegularEx::applyReplace(std::string text, std::string regex, std::string replaceText) {
	try
	{
		replaceText = formatPathForRegex(replaceText);
		text = boost::regex_replace(text, boost::regex(regex), replaceText);
	}
	catch (boost::regex_error& e) {
		// Syntax error in the regular expression
		std::cout << ERR_REGEX << regex << endl;
		std::cout << e.what() << endl;
		exit;
	}
	return text;
}

// Escape Paths for regex
std::string RegularEx::formatPathForRegex(const std::string &s) {
	static const char metacharacters[] = R"(\.^$-+()[]{}|?*)";
	std::string out;
	out.reserve(s.size());
	for (auto ch : s) {
		if (std::strchr(metacharacters, ch))
			out.push_back('\\');
		out.push_back(ch);
	}
	return out;
}

#endif // !REGULAREX_H_INCLUDED
