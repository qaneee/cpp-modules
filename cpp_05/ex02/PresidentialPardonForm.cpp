#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) , target("default")
{
	std::cout << "PresidentialPardonForm's Default Constructor Called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& tg) : AForm("PresidentialPardonForm", 25, 5) , target(tg)
{
	std::cout << "PresidentialPardonForm's Parameritrized Constructor Called!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& obj) : AForm(obj), target(obj.target)
{
	std::cout << "PresidentialPardonForm's Copy Constructor Called!" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	std::cout << "PresidentialPardonForm's Copy Assignment Operator Called!" << std::endl;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm's Destructor Called!" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}