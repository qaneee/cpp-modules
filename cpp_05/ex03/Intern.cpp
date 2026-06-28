#include "Intern.hpp"

Intern::Intern()
{
	std::cout << "Intern's Default Constructor is Called\n";
}

Intern::~Intern()
{
	std::cout << "Intern's Destructor is Called\n";
}

Intern::Intern(const Intern &obj)
{
	std::cout << "Intern's Copy Constructor is Called" << std::endl;
	*this = obj;
}

Intern &Intern::operator=(const Intern &obj)
{
	std::cout << "Intern's Copy Assignment Operator\n" << std::endl;
	(void)obj;
	return *this;
}

static AForm *makeShruberry(const std::string &target)
{
	return new ShrubberyCreationForm(target);
}

static AForm *makePresidental(const std::string &target)
{
	return new PresidentialPardonForm(target);
}

static AForm *makeRobotomy(const std::string &target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *(*creator[3])(const std::string &) = {makeShruberry, makeRobotomy, makePresidental};
	for (int i = 0; i < 3; i++)
	{
		if (form_name == forms[i])
		{
			AForm *form = creator[i](target);
			std::cout << "Intern creates " << form_name << std::endl;
			return form;
		}
	}
	std::cerr << "Error: " << form_name << " does not exist\n";
	return NULL;
}