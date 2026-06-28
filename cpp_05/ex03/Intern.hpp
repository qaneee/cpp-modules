#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern& obj);
		Intern &operator=(const Intern &other);

		AForm *makeForm(const std::string &form_name, const std::string &target) const;
};