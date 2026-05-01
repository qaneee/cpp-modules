#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal")
{
	std::cout << "Default Constructor Called (WrongAnimal)!" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type)
{
	this->type = type;
	std::cout << "Parametrized Constructor Called (WrongAnimal)!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj)
{
	std::cout << "Copy Constructor Called (WrongAnimal)!" << std::endl;
	*this = obj;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj)
{
	std::cout << "Copy Assignment Operator Called (WrongAnimal)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "Destructor Called (WrongAnimal)" << std::endl;
}

void WrongAnimal::makeSound() const
{
	std::cout << "Animal makes sound!" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return type;
}

void WrongAnimal::setType(const std::string &tip)
{
	type = tip;
}
