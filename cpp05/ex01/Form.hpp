#pragma once

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signingGrade;
		const int			_executingGrade;

	public:
		Form();
		Form(const std::string& name, int signingGrade, int executingGrade);
		Form(const Form& obj);
		Form& operator=(const Form& obj);
		~Form();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getSigningGrade() const;
		int					getExecutingGrade() const;

		void				beSigned(const Bureaucrat& b);

		class GradeTooHighException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form grade too high";
				}
		};

		class GradeTooLowException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form grade too low";
				}
		};
};

std::ostream& operator<<(std::ostream& out, const Form& obj);