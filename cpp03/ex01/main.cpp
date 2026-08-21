#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== Basic Construction/Destruction ===" << std::endl;
	{
		ScavTrap s("Rex");
	}

	std::cout << "\n=== Attack ===" << std::endl;
	{
		ScavTrap s("Rex");
		s.attack("enemy");
	}

	std::cout << "\n=== guardGate ===" << std::endl;
	{
		ScavTrap s("Rex");
		s.guardGate();
	}

	std::cout << "\n=== Take damage and heal ===" << std::endl;
	{
		ScavTrap s("Rex");
		s.takeDamage(50);
		s.beRepaired(20);
		s.takeDamage(200);
	}

	std::cout << "\n=== Attack with no energy ===" << std::endl;
	{
		ScavTrap s("Rex");
		for (int i = 0; i <= 50; i++)
			s.attack("enemy");
	}

	std::cout << "\n=== Attack when dead ===" << std::endl;
	{
		ScavTrap s("Rex");
		s.takeDamage(999);
		s.attack("enemy");
		s.guardGate();
	}
	
	std::cout << "\n=== Multiple ScavTraps ===" << std::endl;
	{
		ScavTrap a("Alpha");
		ScavTrap b("Beta");
		a.attack("Beta");
		b.takeDamage(20);
		b.attack("Alpha");
		a.takeDamage(20);
	}
	return (0);
}