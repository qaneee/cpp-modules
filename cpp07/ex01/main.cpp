#include "iter.hpp"
#include <iostream>

int main()
{
	int int_arr[] = {1, 2, 3, 4, 5};
	::iter(int_arr, 5, print<int>);
	std::cout << std::endl;

	std::string string_arr[] = {"hello", "world", "iter", "template"};
	::iter(string_arr, 4, print<std::string>);
	std::cout << std::endl;

	char char_arr[] = {'a', 'b', 'c'};
	::iter(char_arr, 3, print<char>);
	std::cout << std::endl;

	double double_arr[] = {1.1, 2.2, 3.3};
	::iter(double_arr, 3, print<double>);
	std::cout << std::endl;

	return 0;
}