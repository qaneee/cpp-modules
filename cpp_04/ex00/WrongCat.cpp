#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "Default Constructor Called (WrongCat)!" << std::endl;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj)
{
	std::cout << "Copy Constructor Called (WrongCat)!" << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator=(const WrongCat &obj)
{
	std::cout << "Copy Assignment Operator Called (WrongCat)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "Destructor Called (WrongCat)" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}
