#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde_mbr = new Zombie [N];
	for (int i = 0; i < N; i++)
		horde_mbr[i].give_name(name);
	return (horde_mbr);
}