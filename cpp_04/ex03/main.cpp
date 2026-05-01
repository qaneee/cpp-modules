#include "ICharacter.hpp"
#include "IMateriaSource.hpp"
#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

static void printSeparator(std::string const &title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	printSeparator("TEST 1: Subject example");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;
		AMateria* tmp_cure = new Cure();
		src->learnMateria(tmp_cure);
		delete tmp_cure;

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	printSeparator("TEST 2: Unknown materia type");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;

		AMateria* tmp = src->createMateria("fire");
		if (!tmp)
			std::cout << "createMateria(\"fire\") correctly returned 0" << std::endl;
		else
		{
			std::cout << "ERROR: should have returned 0" << std::endl;
			delete tmp;
		}

		delete src;
	}

	printSeparator("TEST 3: Full inventory (4 slots max)");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;
		AMateria* tmp_cure = new Cure();
		src->learnMateria(tmp_cure);
		delete tmp_cure;

		ICharacter* me = new Character("me");

		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));

		AMateria* extra = src->createMateria("ice");
		me->equip(extra); 
		delete extra;

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);

		delete bob;
		delete me;
		delete src;
	}

	printSeparator("TEST 4: Invalid index for use and unequip");
	{
		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		me->use(0, *bob);
		me->use(-1, *bob);
		me->use(4, *bob);
		me->unequip(0);
		me->unequip(99);

		std::cout << "No crash on invalid indices: OK" << std::endl;

		delete bob;
		delete me;
	}

	printSeparator("TEST 5: unequip + manual cleanup");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;

		ICharacter* me = new Character("me");
		AMateria* ice = src->createMateria("ice");
		me->equip(ice);

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);

		me->unequip(0);
		me->use(0, *bob);

		delete ice;

		delete bob;
		delete me;
		delete src;
	}

	printSeparator("TEST 6: Deep copy of Character");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;
		AMateria* tmp_cure = new Cure();
		src->learnMateria(tmp_cure);
		delete tmp_cure;

		Character* alice = new Character("alice");
		alice->equip(src->createMateria("ice"));
		alice->equip(src->createMateria("cure"));

		Character* aliceCopy = new Character(*alice);

		ICharacter* bob = new Character("bob");

		std::cout << "Original alice uses:" << std::endl;
		alice->use(0, *bob);
		alice->use(1, *bob);

		std::cout << "Copied alice uses:" << std::endl;
		aliceCopy->use(0, *bob);
		aliceCopy->use(1, *bob);

		delete bob;
		delete alice;
		delete aliceCopy;
		delete src;
	}

	printSeparator("TEST 7: Copy assignment operator of Character");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;
		AMateria* tmp_cure = new Cure();
		src->learnMateria(tmp_cure);
		delete tmp_cure;

		Character* charlie = new Character("charlie");
		charlie->equip(src->createMateria("ice"));

		Character* dave = new Character("dave");
		dave->equip(src->createMateria("cure"));

		ICharacter* bob = new Character("bob");

		std::cout << "Before assignment, dave uses:" << std::endl;
		dave->use(0, *bob);

		*dave = *charlie;

		std::cout << "After assignment (dave = charlie), dave uses:" << std::endl;
		dave->use(0, *bob);

		delete bob;
		delete charlie;
		delete dave;
		delete src;
	}

	printSeparator("TEST 8: MateriaSource full capacity");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice1 = new Ice();
		src->learnMateria(tmp_ice1);
		delete tmp_ice1;
		AMateria* tmp_cure1 = new Cure();
		src->learnMateria(tmp_cure1);
		delete tmp_cure1;
		AMateria* tmp_ice2 = new Ice();
		src->learnMateria(tmp_ice2);
		delete tmp_ice2;
		AMateria* tmp_cure2 = new Cure();
		src->learnMateria(tmp_cure2);
		delete tmp_cure2;

		AMateria* extra = new Ice();
		src->learnMateria(extra);
		delete extra;

		ICharacter* me = new Character("me");
		ICharacter* bob = new Character("bob");

		me->equip(src->createMateria("ice"));
		me->equip(src->createMateria("cure"));
		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	printSeparator("TEST 9: clone() independence");
	{
		AMateria* original = new Ice();
		AMateria* cloned   = original->clone();

		ICharacter* bob = new Character("bob");

		original->use(*bob);
		cloned->use(*bob);

		std::cout << "Same type? " << (original->getType() == cloned->getType() ? "yes" : "no") << std::endl;
		std::cout << "Same address? " << (original == cloned ? "yes (BAD)" : "no (GOOD)") << std::endl;

		delete bob;
		delete original;
		delete cloned;
	}

	printSeparator("TEST 10: Self-assignment");
	{
		IMateriaSource* src = new MateriaSource();
		AMateria* tmp_ice = new Ice();
		src->learnMateria(tmp_ice);
		delete tmp_ice;

		Character* me = new Character("me");
		me->equip(src->createMateria("ice"));

		*me = *me;

		ICharacter* bob = new Character("bob");
		me->use(0, *bob);

		delete bob;
		delete me;
		delete src;
	}
	std::cout << "\nAll tests done. Check with valgrind for memory leaks!" << std::endl;
	return 0;
}