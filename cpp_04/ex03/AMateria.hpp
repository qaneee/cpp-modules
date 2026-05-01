#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
	protected:
		std::string type;
	
	public:
		AMateria(std::string const & type);
		AMateria();
		AMateria(const AMateria &obj);
		AMateria& operator=(const AMateria& obj);
		virtual ~AMateria();
		
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif