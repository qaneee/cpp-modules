#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), ScavTrap(), FragTrap()
{
	_name = "default";
	hit_point = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "Default constructor of DiamondTrap " << _name << " Called.\n";
}

DiamondTrap::DiamondTrap(const std::string& anun) : ClapTrap(anun + "_clap_name"), ScavTrap(), FragTrap()
{
	_name = anun;
	hit_point = 100;
	energy_points = 50;
	attack_damage = 30;
	std::cout << "Parametrized constructor of DiamondTrap " << _name << " Called.\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : ClapTrap(obj), ScavTrap(obj), FragTrap(obj)
{
	_name = obj._name;
	std::cout << "Copy constructor of DiamondTrap " << _name << " Called.\n";
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& obj)
{
	if (this == &obj)
		return *this;
	ClapTrap::operator=(obj);
	_name = obj._name;
	std::cout << "Copy assignment operator of DiamondTrap " << _name << " Called.\n";
	return *this;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "Destructor of DiamondTrap " << _name << " Called.\n";
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << _name << std::endl;
	std::cout << "ClapTrap name: " << ClapTrap::name << std::endl;
}
