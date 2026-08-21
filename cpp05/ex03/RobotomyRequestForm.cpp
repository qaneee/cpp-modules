#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) , target("default")
{
	std::cout << "RobotomyRequestForm's Default Constructor Called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& tg) : AForm("RobotomyRequestForm", 72, 45) , target(tg)
{
	std::cout << "RobotomyRequestForm's Parameritrized Constructor Called!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& obj) : AForm(obj), target(obj.target)
{
	std::cout << "RobotomyRequestForm's Copy Constructor Called!" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	std::cout << "RobotomyRequestForm's Copy Assignment Operator Called!" << std::endl;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm's Destructor Called!" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::cout << "Drilling noises..." << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}