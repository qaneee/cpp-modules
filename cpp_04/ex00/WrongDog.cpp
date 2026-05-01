#include "WrongDog.hpp"

WrongDog::WrongDog() : WrongAnimal("WrongDog")
{
	std::cout << "Default Constructor Called (WrongDog)!" << std::endl;
}

WrongDog::WrongDog(const WrongDog &obj) : WrongAnimal(obj)
{
	std::cout << "Copy Constructor Called (WrongDog)!" << std::endl;
	*this = obj;
}

WrongDog& WrongDog::operator=(const WrongDog &obj)
{
	std::cout << "Copy Assignment Operator Called (WrongDog)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongDog::~WrongDog()
{
	std::cout << "Destructor Called (WrongDog)" << std::endl;
}

void WrongDog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

