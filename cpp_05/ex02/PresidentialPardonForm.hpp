#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;
	
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& tg);
		PresidentialPardonForm(const PresidentialPardonForm& obj);
		PresidentialPardonForm& operator=(const PresidentialPardonForm& obj);
		~PresidentialPardonForm();

		void execute(Bureaucrat const &executor) const;
};