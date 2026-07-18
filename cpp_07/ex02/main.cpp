#include <iostream>
#include "Array.hpp"

int main(void)
{
	Array<int> a;
	std::cout << "a.size() = " << a.size() << std::endl;

	Array<int> b(5);
	for (unsigned int i = 0; i < b.size(); i++)
		std::cout << "b[" << i << "] = " << b[i] << std::endl;

	for (unsigned int i = 0; i < b.size(); i++)
		b[i] = i * 10;

	Array<int> c(b);
	c[0] = 999;
	std::cout << "b[0] = " << b[0] << " | c[0] = " << c[0] << std::endl;

	Array<int> d;
	d = b;
	d[0] = -1;
	std::cout << "b[0] = " << b[0] << " | d[0] = " << d[0] << std::endl;

	try
	{
		std::cout << b[100] << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "caught: " << e.what() << std::endl;
	}

	Array<std::string> s(2);
	s[0] = "hello";
	std::cout << "s[0] = " << s[0] << std::endl;

	return 0;
}