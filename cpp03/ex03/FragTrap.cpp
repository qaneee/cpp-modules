#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	std::cout << "Default constructor of FragTrap " << name << " Called!" << std::endl;
	hit_point = 100;
	energy_points = 100;
	attack_damage = 30;
}

FragTrap::FragTrap(const std::string &anun) : ClapTrap(anun)
{
	hit_point = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "Parametrized constructor of FragTrap " << name << " Called!" << std::endl;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy constructor of FragTrap " << name << " Called!" << std::endl;
	*this = obj;
}

FragTrap& FragTrap::operator=(const FragTrap &obj)
{
	if (this != &obj)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		attack_damage = obj.attack_damage;
		energy_points = obj.energy_points;
	}
	std::cout << "Copy Assignment Operator of FragTrap " << name << " Called!" << std::endl;
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "Destructor of FragTrap " << name << " Called!" << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << name << " requests a positive high five!" << std::endl;
}
