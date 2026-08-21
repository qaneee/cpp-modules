# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <ctime>
#include <string>
#include <iomanip>
#include <cstdlib>

class Zombie
{
	private:
		std::string	name;
		
	public:
		void announce(void);
		Zombie(std::string name);
		~Zombie();
	};
	
	Zombie	*newZombie(std::string name);
	void	randomChump(std::string name);

# endif