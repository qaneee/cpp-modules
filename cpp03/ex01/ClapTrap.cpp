#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Frank Ocean"), hit_point(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default Constructor of ClapTrap " << name <<" Called!" << std::endl;
}

ClapTrap::ClapTrap(const std::string &anun) : name(anun), hit_point(10), energy_points(10), attack_damage(0)
{
	std::cout << "Parametrized Constructor of ClapTrap "<< name << " Called!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor of ClapTrap "<< name << " Called!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &obj) : name(obj.name), hit_point(obj.hit_point), energy_points(obj.energy_points), attack_damage(obj.attack_damage)
{
	std::cout << "Copy Constructor of ClapTrap "<< name << " Called!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& obj)
{ 
	if (this != &obj)
	{
		name = obj.name;
		hit_point = obj.hit_point;
		attack_damage = obj.attack_damage;
		energy_points = obj.energy_points;
	}
	std::cout << "Copy Assignment Operator of ClapTrap " << name << " Called!" << std::endl;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_point == 0)
	{
		std::cout << "ClapTrap " << name << " can't attack because it has no hit points!" << std::endl;
		return ;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have energy points therefore it can't attack!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name <<" attacks " << target <<", causing "<< attack_damage << " points of damage!" << std::endl;
	energy_points--;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_point == 0)
	{
		std::cout << "ClapTrap " << name << " can't repair because it has no hit points!" << std::endl;
		return ;
	}
	if (energy_points == 0)
	{
		std::cout << "ClapTrap " << name << " doesn't have energy points to repair itself!" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << name << " repairs itself with " << amount <<" points!" << std::endl;
	hit_point += amount;
	energy_points--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_point == 0)
	{
		std::cout << "ClapTrap " << name << " can't take damage because it has no hit points!" << std::endl;
		return ;
	}
	if (amount >= (unsigned int)hit_point)
		hit_point = 0;
	else
		hit_point -= amount;
	std::cout << "ClapTrap " << name << " takes damage of " << amount << " points!" << std::endl;
}