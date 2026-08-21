#pragma once

#include <iostream>
#include <string>
#include <exception>
#include <cstdlib>
#include <ctime>
#include <fstream>

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_signingGrade;
		const int			_executingGrade;

	public:
		AForm();
		AForm(const std::string& name, int signingGrade, int executingGrade);
		AForm(const AForm& obj);
		AForm& operator=(const AForm& obj);
		virtual ~AForm();

		const std::string&	getName() const;
		bool				getIsSigned() const;
		int					getSigningGrade() const;
		int					getExecutingGrade() const;

		void				beSigned(const Bureaucrat& b);

		virtual void execute(Bureaucrat const &executor) const = 0;

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

		class NotSignedException : public std::exception
		{
			public:
				const char* what() const throw()
				{
					return "Form is not signed";
				}
		};
};

std::ostream& operator<<(std::ostream& out, const AForm& obj);