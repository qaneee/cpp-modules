#include <iostream>
#include <cstdlib>

int main(void)
{
	std::string expr = "HI THIS IS BRAIN";

	std::string *stringPTR = &expr;
	std::string &stringREF = expr;

	std::cout << std::endl <<"=== MEMORY ADDRESS ===" << std::endl << std::endl;

	std::cout << "Memory address of the string variable: expr -> " << &expr << std::endl;
	std::cout << "Memory address held by stringPTR: -> " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: -> " << &stringREF << std::endl;

	std::cout << std::endl << "=== VALUE ===" << std::endl << std::endl;

	std::cout << "Value of the string variable: expr -> " << expr << std::endl;
	std::cout << "Value pointed to by stringPTR: -> " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: -> " << stringREF << std::endl;

	return (0);
}