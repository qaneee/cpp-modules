#include "Animal.hpp"

Animal::Animal() : type("Animal")
{
	std::cout << "Default Constructor Called (Animal)!" << std::endl;
}

Animal::Animal(const std::string &type)
{
	this->type = type;
	std::cout << "Parametrized Constructor Called (Animal)!" << std::endl;
}

Animal::Animal(const Animal &obj)
{
	std::cout << "Copy Constructor Called (Animal)!" << std::endl;
	*this = obj;
}

Animal &Animal::operator=(const Animal &obj)
{
	std::cout << "Copy Assignment Operator Called (Animal)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Animal::~Animal()
{
	std::cout << "Destructor Called (Animal)" << std::endl;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes sound!" << std::endl;
}

std::string Animal::getType() const
{
	return type;
}


void Animal::setType(const std::string &tip)
{
	type = tip;
}
