#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Default Constructor Called (Ice)!" << std::endl;
}

Ice::Ice(const Ice &obj) : AMateria(obj)
{
	std::cout << "Copy Constructor Called (Ice)!" << std::endl;
}

Ice &Ice::operator=(const Ice &obj)
{
	std::cout << "Copy Assignment Operator (Ice)!" << std::endl;
	if (this != &obj)
		AMateria::operator=(obj);
	return *this;
}

Ice::~Ice()
{
	std::cout << "Destructor Called (Ice)!" << std::endl;
}

AMateria *Ice::clone() const
{
	return new Ice(*this);
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" <<std::endl;
}