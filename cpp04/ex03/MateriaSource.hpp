#pragma once

#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
private:
	AMateria* materias[4];
public:
	MateriaSource();
	MateriaSource(const MateriaSource &obj);
	MateriaSource& operator=(const MateriaSource &obj);
	~MateriaSource();

	void learnMateria(AMateria* a);
	AMateria* createMateria(std::string const & type);
};