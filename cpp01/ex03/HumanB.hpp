# ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
	private:
		std::string name;
		Weapon* weapon;
	public:
		~HumanB();
		void attack();
		void setWeapon(Weapon& w);
		HumanB(std::string name);
};

# endif