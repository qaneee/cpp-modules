#include "Zombie.hpp"

int main()
{
	std::cout << "--- Test 1: horde of 5 'Walker' ---" << std::endl;
	Zombie* horde1 = zombieHorde(5, "Walker");
	for (int i = 0; i < 5; i++)
		horde1[i].announce();
	delete[] horde1;
	
	std::cout << "\n--- Test 2: horde of 1 'Loner' ---" << std::endl;
	Zombie* horde2 = zombieHorde(1, "Loner");
	horde2[0].announce();
	delete[] horde2;
	
	std::cout << "\n--- Test 3: two separate hordes ---" << std::endl;
	Zombie* alphas = zombieHorde(3, "Alpha");
	Zombie* betas  = zombieHorde(3, "Beta");
	for (int i = 0; i < 3; i++) alphas[i].announce();
	for (int i = 0; i < 3; i++) betas[i].announce();
	delete[] alphas;
	delete[] betas;

	std::cout << "\n--- Test 4: horde of 10 'Horde' ---" << std::endl;
	Zombie* horde4 = zombieHorde(10, "Horde");
	for (int i = 0; i < 10; i++)
		horde4[i].announce();
	delete[] horde4;
	
	return 0;
}