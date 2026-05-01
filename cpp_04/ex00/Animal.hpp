#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include <iomanip>

class Animal
{
	protected:
		std::string type;

	public:
		Animal();
		Animal(const std::string &type);
		Animal(const Animal &obj);
		Animal& operator=(const Animal &obj);
		virtual ~Animal();

		virtual void makeSound() const;
		std::string getType() const;
		void setType(const std::string &tip);
};

#endif