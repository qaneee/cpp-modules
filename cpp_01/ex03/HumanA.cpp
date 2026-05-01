#include "HumanA.hpp"

HumanA::~HumanA()
{
	std::cout << name << " was destroyed." << std::endl;
}

HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon)
{
	std::cout << name << " was created." << std::endl;
}

void HumanA::attack()
{
	std::cout << name << " attacks with their " << weapon.getType() << std::endl;
}