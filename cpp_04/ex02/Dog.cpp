#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain())
{
	std::cout << "Default Constructor Called (Dog)!" << std::endl;
}

Dog::Dog(const Dog &obj) : AAnimal(obj), brain(NULL)
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
	delete brain;
	std::cout << "Destructor Called (Dog)" << std::endl;
}

void Dog::makeSound() const
{
	std::cout << "Woof Woof!" << std::endl;
}

Brain *Dog::getBrain() const
{
	return brain;
}
