#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== Basic Construction/Destruction ===" << std::endl;
	{
		DiamondTrap d("Rex");
	}

	std::cout << "\n=== whoAmI ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.whoAmI();
	}

	std::cout << "\n=== Attack (ScavTrap's) ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.attack("enemy");
	}

	std::cout << "\n=== guardGate (ScavTrap's) ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.guardGate();
	}

	std::cout << "\n=== highFivesGuys (FragTrap's) ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.highFivesGuys();
	}

	std::cout << "\n=== Take damage and heal ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.takeDamage(50);
		d.beRepaired(20);
		d.takeDamage(200);
	}

	std::cout << "\n=== Attack when dead ===" << std::endl;
	{
		DiamondTrap d("Rex");
		d.takeDamage(999);
		d.attack("enemy");
		d.whoAmI();
	}

	std::cout << "\n=== Multiple DiamondTraps ===" << std::endl;
	{
		DiamondTrap a("Alpha");
		DiamondTrap b("Beta");
		a.whoAmI();
		b.whoAmI();
		a.attack("Beta");
		b.takeDamage(30);
	}
}