#include "Zombie.hpp"

int main(void)
{
	std::cout << std::endl << "==> Heap Zombie <==" << std::endl;
	Zombie *zb1 = newZombie("Heap_Zombie");
	zb1->announce();
	delete zb1;


	std::cout << std::endl << "==> Stack Zombie <==" <<std::endl;
	randomChump("Stack_Zombie");
	return (0);
}