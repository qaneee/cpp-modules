#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>
#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <climits>
#include <sstream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &other);
		ScalarConverter &operator=(const ScalarConverter &other);
		~ScalarConverter();

		
		static bool getChar(const std::string &lit, char &c);
		static bool getInt(const std::string &lit, int &i);
		static bool getFloat(const std::string &lit, double &d);
		static bool getDouble(const std::string &lit, double &d);

	public:
		static void convert(const std::string &literal);
};

#endif