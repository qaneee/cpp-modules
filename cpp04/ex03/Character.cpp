#include "Character.hpp"

Character::Character()
{
	this->name = "default";
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	std::cout << "Default Constructor Called (Character)!" << std::endl;
}

Character::Character(const std::string &name)
{
	this->name = name;
	for (int i = 0; i < 4; i++)
		slot[i] = NULL;
	std::cout << "Parametrized Constructor Called (Character)!" << std::endl;
}

Character::Character(const Character &obj) : name(obj.name)
{
	for (int i = 0; i < 4; i++)
	{
		if (obj.slot[i])
			this->slot[i] = obj.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
	std::cout << "Copy Constructor Called (Character)!" << std::endl;
}

Character &Character::operator=(const Character &obj)
{
	std::cout << "Copy Assignment Operator (Character)!" << std::endl;
	if (this == &obj)
		return *this;
	this->name = obj.name;
	for (int i = 0; i < 4; i++)
	{
		delete this->slot[i];
		if (obj.slot[i] != NULL)
			this->slot[i] = obj.slot[i]->clone();
		else
			this->slot[i] = NULL;
	}
	return *this;
}

Character::~Character()
{
	std::cout << "Destructor Called (Character)!" << std::endl;
	for (int i = 0; i < 4; i++)
		delete this->slot[i];
}

std::string const & Character::getName() const
{
	return name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return ;
	for (int i = 0; i < 4; i++)
	{
		if (slot[i] == NULL)
		{
			slot[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx >= 0 && idx < 4 && slot[idx] != NULL)
		slot[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx >= 0 && idx < 4 && slot[idx] != NULL)
		slot[idx]->use(target);
}
