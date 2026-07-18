#pragma once

#include <iostream>
#include <iomanip>
#include <limits>
#include <cstdlib>
#include <cctype>
#include <string>
#include <climits>
#include <cmath>

enum e_type
{
	TYPE_INT,
	TYPE_FLOAT,
	TYPE_DOUBLE,
	TYPE_CHAR,
	TYPE_INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter&);
		ScalarConverter &operator=(const ScalarConverter&);
		~ScalarConverter();

	public:
		static void convert(const std::string &literal);
};
