#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat();

		void makeSound() const;
};