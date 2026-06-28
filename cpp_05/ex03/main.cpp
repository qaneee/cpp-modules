#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

static void separator(const std::string &label)
{
	std::cout << "\n----- " << label << " -----" << std::endl;
}

int main()
{
	separator("makeForm(\"robotomy request\", \"Bender\")");
	{
		Intern someRandomIntern;
		AForm *rrf;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

		Bureaucrat director("Director", 1);
		director.signForm(*rrf);
		director.executeForm(*rrf);
		delete rrf;
	}

	separator("makeForm(\"shrubbery creation\", ...)");
	{
		Intern intern;
		AForm *form = intern.makeForm("shrubbery creation", "garden");

		Bureaucrat director("Director", 1);
		director.signForm(*form);
		director.executeForm(*form);
		delete form;
	}

	separator("makeForm(\"presidential pardon\", ...)");
	{
		Intern intern;
		AForm *form = intern.makeForm("presidential pardon", "Frank Ocean");

		Bureaucrat president("President", 1);
		president.signForm(*form);
		president.executeForm(*form);
		delete form;
	}

	separator("makeForm() with an unknown form name -> explicit error message, NULL returned");
	{
		Intern intern;
		AForm *form = intern.makeForm("haircut request", "no one");

		if (form == NULL)
			std::cout << "Confirmed: NULL returned for an unknown form name." << std::endl;
		else
		{
			std::cout << "BUG: expected NULL, got a real pointer." << std::endl;
			delete form;
		}
	}

	return 0;
}