# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <stdlib.h>

class Zombie
{
	private:
		std::string	name;

	public:
		void announce(void);
		Zombie(std::string name);
		Zombie();
		~Zombie();
		void give_name(const std::string &given_name);
};
	
	Zombie* zombieHorde(int N, std::string name);

# endif