#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string target;
	
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& tg);
		ShrubberyCreationForm(const ShrubberyCreationForm& obj);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& obj);
		~ShrubberyCreationForm();

		void execute(Bureaucrat const &executor) const;
};