#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
	std::cout << name << ": Created" << std::endl;
}

Zombie::Zombie()
{
}


Zombie::~Zombie()
{
	std::cout << name << ": Destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::give_name(const std::string &give_name)
{
	this->name = give_name;
}
