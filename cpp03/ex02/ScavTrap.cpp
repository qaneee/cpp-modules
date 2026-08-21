#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	std::cout << "Default constructor of ScavTrap " << name << " Called!" << std::endl;
	hit_point = 100;
	energy_points = 50;
	attack_damage = 20;
}

ScavTrap::ScavTrap(const std::string &anun) : ClapTrap(anun)
{
	hit_point = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "Parametrized constructor of ScavTrap " << name << " Called!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj)
{
	std::cout << "Copy constructor of ScavTrap " << name << " Called!" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap &obj)
{
	std::cout << "Copy Assignment Operator of ScavTrap " << name << " Called!" << std::endl;
	if (this != &obj)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		attack_damage = obj.attack_damage;
		energy_points = obj.energy_points;
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "Destructor of ScavTrap " << name << " Called!" << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_point == 0)
	{
		std::cout << "ScavTrap " << name << " can't attack because it has no hit points" << std::endl;
		return ;
	}
	if (energy_points == 0)
	{
		std::cout << "ScavTrap " << name << " doesn't have energy points therefore can't attack" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << name <<" attacks " << target <<", causing "<< attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode!" << std::endl;
}
