#include "FragTrap.hpp"

int main()
{
	std::cout << "=== Basic Construction/Destruction ===" << std::endl;
	{
		FragTrap f("Rex");
	}

	std::cout << "\n=== Attack ===" << std::endl;
	{
		FragTrap f("Rex");
		f.attack("enemy");
	}

	std::cout << "\n=== highFivesGuys ===" << std::endl;
	{
		FragTrap f("Rex");
		f.highFivesGuys();
	}

	std::cout << "\n=== Take damage and heal ===" << std::endl;
	{
		FragTrap f("Rex");
		f.takeDamage(50);
		f.beRepaired(20);
		f.takeDamage(200);
	}

	std::cout << "\n=== Attack with no energy ===" << std::endl;
	{
		FragTrap f("Rex");
		for (int i = 0; i <= 100; i++)
			f.attack("enemy");
	}

	std::cout << "\n=== Attack when dead ===" << std::endl;
	{
		FragTrap f("Rex");
		f.takeDamage(999);
		f.attack("enemy");
		f.highFivesGuys();
	}

	std::cout << "\n=== Multiple FragTraps ===" << std::endl;
	{
		FragTrap a("Alpha");
		FragTrap b("Beta");
		a.attack("Beta");
		b.takeDamage(30);
		b.attack("Alpha");
		a.takeDamage(30);
	}
}