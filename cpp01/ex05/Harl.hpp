#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

#define POSSIBLE_OPTIONS 4

class Harl
{
	private:
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
		public:
			Harl();
			~Harl();
			void complain(std::string level);
};

#endif