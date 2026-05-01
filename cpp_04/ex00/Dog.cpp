#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
	std::cout << "Default Constructor Called (Dog)!" << std::endl;
}

Dog::Dog(const Dog &obj) : Animal(obj)
{
	std::cout << "Copy Constructor Called (Dog)!" << std::endl;
	*this = obj;
}

Dog& Dog::operator=(const Dog &obj)
{
	std::cout << "Copy Assignment Operator Called (Dog)" << std::endl;
	if (this != &obj)
		type = obj.type;
	return *this;
}

Dog::~Dog()
{
	std::cout << "Destructor Called (Dog)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}
