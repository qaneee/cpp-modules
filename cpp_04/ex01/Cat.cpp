#include "Cat.hpp"

Cat::Cat() : Animal("Cat"), brain(new Brain())
{
	std::cout << "Default Constructor Called (Cat)!" << std::endl;
}

Cat::Cat(const Cat &obj) : Animal(obj), brain(NULL)
{
	std::cout << "Copy Constructor Called (Cat)!" << std::endl;
	*this = obj;
}

Cat& Cat::operator=(const Cat &obj)
{
	std::cout << "Copy Assignment Operator Called (Cat)" << std::endl;
	if (this != &obj)
	{
		Animal::operator=(obj);
		delete brain;
		brain = new Brain(*obj.brain);
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Destructor Called (Cat)" << std::endl;
}

void Cat::makeSound() const
{
	std::cout << "Meow Meow!" << std::endl;
}

Brain* Cat::getBrain() const
{
	return brain;
}