#include "Bureaucrat.hpp"
#include <iostream>

static void separator(const std::string &label)
{
	std::cout << "\n----- " << label << " -----" << std::endl;
}

int main()
{
	separator("Valid construction + operator<< format check");
	{
		Bureaucrat a("Director", 1);
		Bureaucrat b("Junior Clerk", 150);
		Bureaucrat c("Mid Manager", 75);

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
	}

	separator("getName() / getGrade() return correct values");
	{
		Bureaucrat a("Director", 1);
		std::cout << "Name: " << a.getName() << std::endl;
		std::cout << "Grade: " << a.getGrade() << std::endl;
	}

	separator("Construction with grade < 1 -> GradeTooHighException");
	{
		try
		{
			Bureaucrat bad("Overpromoted", 0);
			std::cout << "BUG: no exception thrown for grade 0" << std::endl;
			(void)bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}
	{
		try
		{
			Bureaucrat bad("Overpromoted", -5);
			std::cout << "BUG: no exception thrown for grade -5" << std::endl;
			(void)bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}

	separator("Construction with grade > 150 -> GradeTooLowException");
	{
		try
		{
			Bureaucrat bad("Underqualified", 151);
			std::cout << "BUG: no exception thrown for grade 151" << std::endl;
			(void)bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}

	separator("Boundary values: grade 1 and grade 150 are BOTH valid");
	{
		try
		{
			Bureaucrat edgeHigh("Edge High", 1);
			Bureaucrat edgeLow("Edge Low", 150);
			std::cout << "No exception for boundary values, as expected:" << std::endl;
			std::cout << edgeHigh << std::endl;
			std::cout << edgeLow << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "BUG: boundary value incorrectly rejected: " << e.what() << std::endl;
		}
	}

	separator("incrementGrade() lowers the grade number (3 -> 2)");
	{
		Bureaucrat a("Climber", 3);
		std::cout << "Before increment: " << a << std::endl;
		a.incrementGrade();
		std::cout << "After increment:  " << a << std::endl;
		if (a.getGrade() == 2)
			std::cout << "Correct: grade 3 incremented to grade 2" << std::endl;
		else
			std::cout << "BUG: expected grade 2, got " << a.getGrade() << std::endl;
	}

	separator("decrementGrade() raises the grade number (3 -> 4)");
	{
		Bureaucrat a("Faller", 3);
		std::cout << "Before decrement: " << a << std::endl;
		a.decrementGrade();
		std::cout << "After decrement:  " << a << std::endl;
		if (a.getGrade() == 4)
			std::cout << "Correct: grade 3 decremented to grade 4" << std::endl;
		else
			std::cout << "BUG: expected grade 4, got " << a.getGrade() << std::endl;
	}

	separator("incrementGrade() at grade 1 -> GradeTooHighException, no mutation");
	{
		Bureaucrat a("Already Top", 1);
		try
		{
			a.incrementGrade();
			std::cout << "BUG: no exception thrown, grade is now " << a.getGrade() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
			std::cout << "Grade unchanged: " << a.getGrade() << " (should still be 1)" << std::endl;
		}
	}

	separator("decrementGrade() at grade 150 -> GradeTooLowException, no mutation");
	{
		Bureaucrat a("Already Bottom", 150);
		try
		{
			a.decrementGrade();
			std::cout << "BUG: no exception thrown, grade is now " << a.getGrade() << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
			std::cout << "Grade unchanged: " << a.getGrade() << " (should still be 150)" << std::endl;
		}
	}

	separator("Copy constructor and copy assignment produce independent objects");
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copyConstructed(original);
		Bureaucrat copyAssigned("Placeholder", 99);
		copyAssigned = original;

		std::cout << "Original:        " << original << std::endl;
		std::cout << "Copy-constructed: " << copyConstructed << std::endl;
		std::cout << "Copy-assigned:    " << copyAssigned << std::endl;

		copyConstructed.incrementGrade();
		std::cout << "After incrementing the copy only:" << std::endl;
		std::cout << "Original (should be unchanged): " << original << std::endl;
		std::cout << "Copy (should have changed):      " << copyConstructed << std::endl;
	}

	separator("Default constructor produces a usable object");
	{
		Bureaucrat def;
		std::cout << def << std::endl;
	}

	return 0;
}