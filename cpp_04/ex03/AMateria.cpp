#include "AMateria.hpp"

AMateria::AMateria() : type("default")
{
	std::cout << "Default Constructor Called (AMateria)!" << std::endl;
}

AMateria::AMateria(std:: string const & type)
{
	this->type = type;
	std::cout << "Parametrized Constructor Called (AMateria)!" << std::endl;
}


AMateria::AMateria(const AMateria &obj)
{
	*this = obj;
	std::cout << "Copy Constructor Called (AMateria)!" << std::endl;
}

AMateria &AMateria::operator=(const AMateria &obj)
{
	std::cout << "Copy Assignment Operator (AMateria)!" << std::endl;
	if (this != &obj)
		this->type = obj.type;
	return *this;
}

AMateria::~AMateria()
{
	std::cout << "Destructor Called (AMateria)!" << std::endl;
}

std::string const& AMateria::getType() const
{
	return type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << "* Some materia is used " << target.getName() << " *" << std::endl;
}