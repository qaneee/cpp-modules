# ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap& operator=(const FragTrap &obj);
		~FragTrap();
		FragTrap(const std::string &anun);
		FragTrap(const FragTrap &obj);

		void highFivesGuys(void);
};

#endif