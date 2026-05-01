# ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap();
		ScavTrap& operator=(const ScavTrap &obj);
		~ScavTrap();
		ScavTrap(const std::string &anun);
		ScavTrap(const ScavTrap &obj);

		void attack(const std::string& target);
		void guardGate();
};

#endif