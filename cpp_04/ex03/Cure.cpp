#include "Cure.hpp"
#include "AMateria.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Default Constructor Called (Cure)!" << std::endl;
}

Cure::Cure(const Cure &obj) : AMateria(obj)
{
	std::cout << "Copy Constructor Called (Cure)!" << std::endl;
}

Cure &Cure::operator=(const Cure &obj)
{
	std::cout << "Copy Assignment Operator (Cure)!" << std::endl;
	if (this != &obj)
		AMateria::operator=(obj);
	return *this;
}

Cure::~Cure()
{
	std::cout << "Destructor Called (Cure)!" << std::endl;
}

AMateria *Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}