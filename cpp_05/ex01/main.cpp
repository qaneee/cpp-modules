#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

static void separator(const std::string &label)
{
	std::cout << "\n----- " << label << " -----" << std::endl;
}

int main()
{
	separator("Valid Form construction + operator<< format check");
	{
		Form f("Tax Form", 50, 30);
		std::cout << f << std::endl;
		std::cout << "Name: " << f.getName() << std::endl;
		std::cout << "Signed: " << (f.getIsSigned() ? "yes" : "no") << std::endl;
		std::cout << "Signing grade: " << f.getSigningGrade() << std::endl;
		std::cout << "Executing grade: " << f.getExecutingGrade() << std::endl;
	}

	separator("Form starts unsigned at construction");
	{
		Form f("Permit", 10, 5);
		if (f.getIsSigned() == false)
			std::cout << "Correct: new form is not signed" << std::endl;
		else
			std::cout << "BUG: new form should not be signed yet" << std::endl;
	}

	separator("Form construction with signingGrade < 1 -> GradeTooHighException");
	{
		try
		{
			Form bad("Bad Form", 0, 50);
			std::cout << "BUG: no exception thrown" << std::endl;
			(void)bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}

	separator("Form construction with executingGrade > 150 -> GradeTooLowException");
	{
		try
		{
			Form bad("Bad Form", 50, 151);
			std::cout << "BUG: no exception thrown" << std::endl;
			(void)bad;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
		}
	}

	separator("Boundary grades 1 and 150 are both valid for a Form");
	{
		try
		{
			Form edge("Edge Form", 1, 150);
			std::cout << "No exception, as expected: " << edge << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "BUG: boundary value incorrectly rejected: " << e.what() << std::endl;
		}
	}

	separator("beSigned(): sufficient grade signs the form successfully");
	{
		Bureaucrat highGrade("Director", 10);
		Form f("Budget Approval", 50, 25);

		f.beSigned(highGrade);
		std::cout << "After beSigned: " << f << std::endl;
		if (f.getIsSigned())
			std::cout << "Correct: form is now signed" << std::endl;
		else
			std::cout << "BUG: form should be signed" << std::endl;
	}

	separator("beSigned(): insufficient grade throws Form::GradeTooLowException, form stays unsigned");
	{
		Bureaucrat lowGrade("Junior Clerk", 100);
		Form f("Budget Approval", 50, 25);

		try
		{
			f.beSigned(lowGrade);
			std::cout << "BUG: no exception thrown" << std::endl;
		}
		catch (std::exception &e)
		{
			std::cout << "Caught as expected: " << e.what() << std::endl;
			std::cout << "Form still unsigned: " << (f.getIsSigned() ? "BUG, signed" : "correct, not signed") << std::endl;
		}
	}

	separator("beSigned(): exact boundary grade (== signingGrade) succeeds");
	{
		Bureaucrat exactGrade("Exact Match", 50);
		Form f("Boundary Test", 50, 25);

		f.beSigned(exactGrade);
		std::cout << (f.getIsSigned() ? "Correct: grade == signingGrade signs successfully" : "BUG") << std::endl;
	}

	separator("signForm(): success path prints '<bureaucrat> signed <form>'");
	{
		Bureaucrat highGrade("Director", 1);
		Form f("Robotomy Request", 72, 45);

		highGrade.signForm(f);
		std::cout << "Form state after signForm: " << f << std::endl;
	}

	separator("signForm(): failure path");
	{
		Bureaucrat lowGrade("Junior Clerk", 150);
		Form f("Robotomy Request", 72, 45);

		lowGrade.signForm(f);
		std::cout << "Form state after failed signForm: " << f << std::endl;
		if (!f.getIsSigned())
			std::cout << "Correct: form remains unsigned after failed attempt" << std::endl;
	}

	separator("Form copy constructor and copy assignment");
	{
		Form original("Original Form", 40, 20);
		Bureaucrat signer("Signer", 10);
		original.beSigned(signer);

		Form copyConstructed(original);
		std::cout << "Original:         " << original << std::endl;
		std::cout << "Copy-constructed: " << copyConstructed << std::endl;

		Form copyAssigned("Placeholder Form", 99, 99);
		copyAssigned = original;
		std::cout << "Copy-assigned:    " << copyAssigned << std::endl;

		if (copyConstructed.getName() == "Original Form" && copyAssigned.getName() == "Placeholder Form")
			std::cout << "Correct: const _name is never reassigned by operator=" << std::endl;
	}

	separator("Default Form constructor produces a usable object");
	{
		Form f;
		std::cout << f << std::endl;
	}

	return 0;
}