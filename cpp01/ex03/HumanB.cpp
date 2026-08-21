#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->weapon = NULL;

	std::cout << name << " was created." << std::endl;
}

HumanB::~HumanB()
{
		std::cout << name << " was destroyed." << std::endl;
}

void HumanB::attack()
{
	if (this->weapon)
		std::cout << name << " attacks with their " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& w)
{
	this->weapon = &w;
}
