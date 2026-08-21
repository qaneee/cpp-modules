#include "AAnimal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main()
{
	std::cout << "=== BASIC TEST ===" << std::endl;

	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound();
	cat->makeSound();

	delete dog;
	delete cat;

	std::cout << "\n=== ARRAY TEST ===" << std::endl;

	const int size = 4;
	AAnimal* animals[size];

	for (int i = 0; i < size; i++)
	{
		if (i % 2 == 0)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < size; i++)
	{
		animals[i]->makeSound();
	}

	for (int i = 0; i < size; i++)
	{
		delete animals[i];
	}

	std::cout << "\n=== DEEP COPY TEST ===" << std::endl;

	Dog original;
	Dog copy = original;

	Dog assigned;
	assigned = original;

	std::cout << "Copy and assignment done." << std::endl;

	std::cout << "\n=== POLYMORPHISM TEST ===" << std::endl;

	AAnimal* a = new Dog();
	AAnimal* b = new Cat();

	a->makeSound();
	b->makeSound();

	delete a;
	delete b;

	std::cout << "\n=== END OF TEST ===" << std::endl;
	return 0;
}