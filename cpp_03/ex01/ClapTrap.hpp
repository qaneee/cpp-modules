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
		virtual ~ClapTrap();
		ClapTrap(const std::string &anun);
		ClapTrap(const ClapTrap &obj);

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string name;
		int hit_point;
		int energy_points;
		int attack_damage;
};

# endif