#include "WrongAnimal.hpp"

class WrongDog : public WrongAnimal
{
	public:
		WrongDog();
		WrongDog(const WrongDog &obj);
		WrongDog& operator=(const WrongDog &obj);
		~WrongDog();

		void makeSound() const;
};