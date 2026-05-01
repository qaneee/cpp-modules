#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain *brain;

	public:
		Cat();
		Cat(const Cat &obj);
		Cat& operator=(const Cat &obj);
		~Cat();

		void makeSound() const;
		Brain *getBrain() const;
};