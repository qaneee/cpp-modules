#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;
	
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& tg);
		RobotomyRequestForm(const RobotomyRequestForm& obj);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& obj);
		~RobotomyRequestForm();

		void execute(Bureaucrat const &executor) const;
};