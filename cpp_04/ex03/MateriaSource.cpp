#include "MateriaSource.hpp"
#include "AMateria.hpp"

MateriaSource::MateriaSource()
{
	std::cout << "Default Constructor Called (MateriaSource)!" << std::endl;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& obj)
{
	std::cout << "Copy constructor called (MateriaSource)!" << std::endl;
	for (int i = 0; i < 4; i++)
		materias[i] = NULL;
	*this = obj;
}

MateriaSource& MateriaSource::operator=(const MateriaSource& obj)
{
	std::cout << "Copy assignment operator called (MateriaSource)!" << std::endl;
	if (this == &obj)
		return *this;
	for (int i = 0; i < 4; i++)
	{
		delete materias[i];
		materias[i] = NULL;
		if (obj.materias[i] != NULL)
			materias[i] = obj.materias[i]->clone();
	}
	return *this;
}

MateriaSource::~MateriaSource()
{
	std::cout << "Destructor called (MateriaSource)!" << std::endl;
	for (int i = 0; i < 4; i++)
		delete materias[i];
}

void MateriaSource::learnMateria(AMateria* a)
{
	if (!a)
		return;
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] == NULL)
		{
			materias[i] = a->clone();
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (materias[i] != NULL && materias[i]->getType() == type)
			return materias[i]->clone();
	}
	return 0;
}