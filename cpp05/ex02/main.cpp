#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

static void separator(const std::string &label)
{
	std::cout << "\n----- " << label << " -----" << std::endl;
}

int main()
{
	separator("ShrubberyCreationForm: creates <target>_shrubbery with ASCII trees");
	{
		Bureaucrat director("Director", 1);
		ShrubberyCreationForm shrub("garden");

		director.signForm(shrub);
		director.executeForm(shrub);
	}

	separator("RobotomyRequestForm: drilling noises, then 50/50 success/failure message");
	{
		Bureaucrat director("Director", 1);
		RobotomyRequestForm robo("Bender");

		director.signForm(robo);
		director.executeForm(robo);
	}

	separator("PresidentialPardonForm: target pardoned by Zaphod Beeblebrox");
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Frank Ocean");

		president.signForm(pardon);
		president.executeForm(pardon);
	}

	separator("execute(): unsigned form throws -> caught by executeForm's explicit error message");
	{
		Bureaucrat director("Director", 1);
		PresidentialPardonForm pardon("Edward Elric");

		director.executeForm(pardon);
	}

	separator("execute(): signed but executor's grade too low -> explicit error message");
	{
		Bureaucrat junior("Junior Clerk", 150);
		Bureaucrat director("Director", 1);
		RobotomyRequestForm robo("Marvin");

		director.signForm(robo);
		junior.executeForm(robo);
	}

	separator("executeForm(): success message format '<bureaucrat> executed <form>'");
	{
		Bureaucrat director("Director", 1);
		ShrubberyCreationForm shrub("office");

		director.signForm(shrub);
		director.executeForm(shrub);
	}

	return 0;
}