#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
	std::cout << "=== Basic polymorphism ===" << std::endl;
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();
	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	delete dog;
	delete cat;

	std::cout << "\n=== Animal array ===" << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 5; i++)
		animals[i] = new Dog();
	for (int i = 5; i < 10; i++)
		animals[i] = new Cat();
	for (int i = 0; i < 10; i++)
		animals[i]->makeSound();
	std::cout << "\n-- Deleting array --" << std::endl;
	for (int i = 0; i < 10; i++)
		delete animals[i];

	std::cout << "\n=== Deep copy Dog ===" << std::endl;
	Dog d1;
	d1.getBrain()->setIdea(0, "I love bones");
	Dog d2(d1);
	d2.getBrain()->setIdea(0, "I prefer kibble");
	std::cout << "d1 idea[0]: " << d1.getBrain()->getIdea(0) << std::endl;
	std::cout << "d2 idea[0]: " << d2.getBrain()->getIdea(0) << std::endl;
	if (d1.getBrain() != d2.getBrain())
		std::cout << "Brain pointers differ -> deep copy OK" << std::endl;
	else
		std::cout << "ERROR: shallow copy!" << std::endl;

	std::cout << "\n=== Deep copy Cat ===" << std::endl;
	Cat c1;
	c1.getBrain()->setIdea(0, "Knock things off tables");
	Cat c2;
	c2 = c1;
	c2.getBrain()->setIdea(0, "Sleep all day");
	std::cout << "c1 idea[0]: " << c1.getBrain()->getIdea(0) << std::endl;
	std::cout << "c2 idea[0]: " << c2.getBrain()->getIdea(0) << std::endl;
	if (c1.getBrain() != c2.getBrain())
		std::cout << "Brain pointers differ -> deep copy OK" << std::endl;
	else
		std::cout << "ERROR: shallow copy!" << std::endl;

	std::cout << "\n=== No leak check ===" << std::endl;
	const Animal *j = new Dog();
	const Animal *i = new Cat();
	delete j;
	delete i;

	return 0;
}
