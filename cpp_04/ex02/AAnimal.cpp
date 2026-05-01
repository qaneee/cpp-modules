#include "AAnimal.hpp"

AAnimal::AAnimal() : type("AAnimal")
{
	std::cout << "Default Constructor Called (AAnimal)!" << std::endl;
}

AAnimal::AAnimal(const std::string &type)
{
	this->type = type;
	std::cout << "Parametrized Constructor Called (AAnimal)!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &obj)
{
	std::cout << "Copy Constructor Called (AAnimal)!" << std::endl;
	*this = obj;
}

AAnimal &AAnimal::operator=(const AAnimal &obj)
{
	std::cout << "Copy Assignment Operator Called (AAnimal)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

AAnimal::~AAnimal()
{
	std::cout << "Destructor Called (AAnimal)" << std::endl;
}

void AAnimal::makeSound() const
{
	std::cout << "AAnimal makes sound!" << std::endl;
}

std::string AAnimal::getType() const
{
	return type;
}

void AAnimal::setType(const std::string &tip)
{
	type = tip;
}
