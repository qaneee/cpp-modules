#include "Base.hpp"
#include <iostream>

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

int main()
{
	Base* obj = generate();

	std::cout << "Test (pointer): ";
	identify(obj);

	std::cout << "Test (reference): ";
	identify(*obj);

	delete obj;
	return 0;
}
