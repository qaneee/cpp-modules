# ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>

class ClapTrap
{
	public:
		ClapTrap();
		ClapTrap& operator=(const ClapTrap &obj);
		~ClapTrap();
		ClapTrap(const std::string &anun);
		ClapTrap(const ClapTrap &obj);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:
		std::string name;
		int hit_point;
		int energy_points;
		int attack_damage;
};

# endif