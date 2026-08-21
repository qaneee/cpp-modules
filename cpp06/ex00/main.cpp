#include "ScalarConverter.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		ScalarConverter::convert(std::string(argv[1]));
	}
	else
	{
		std::cerr << "Wrong Argument Count!\n";
		return 1;
	}
	return 0;
}
