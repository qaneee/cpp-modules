#include "ClapTrap.hpp"

#include "ClapTrap.hpp"

static void printSeparator(const std::string &label)
{
	std::cout << "\n========== " << label << " ==========\n" << std::endl;
}

int main(void)
{
	printSeparator("Construction");
	ClapTrap a("Alpha");
	ClapTrap b("Beta");
	ClapTrap c(a);
	ClapTrap d("Delta");
	d = b;

	printSeparator("Basic Attack");
	a.attack("some enemy");
	b.attack("another enemy");

	printSeparator("Take Damage");
	a.takeDamage(5);
	a.takeDamage(3);

	printSeparator("Repair");
	a.beRepaired(4);

	printSeparator("Energy Exhaustion");
	for (int i = 0; i < 9; ++i)
		b.attack("dummy");
	b.attack("dummy");
	b.beRepaired(5);

	printSeparator("Death by Damage");
	ClapTrap dying("Goner");
	dying.takeDamage(10);
	dying.attack("nobody");
	dying.beRepaired(1);

	printSeparator("Edge Cases");
	ClapTrap edge("Edge");
	edge.takeDamage(0);
	edge.beRepaired(0);
	edge.attack("wall");

	printSeparator("Scope Destruction");
	{
		ClapTrap temp("Temp");
		temp.attack("air");
	}

	printSeparator("End of main — remaining objects destroyed");
	return 0;
}