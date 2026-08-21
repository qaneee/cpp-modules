#include "Bureaucrat.hpp"
#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _signingGrade(20), _executingGrade(15)
{
	std::cout << "Form's Default Constructor Called!" << std::endl;
}

Form::Form(const std::string& name, int signingGrade, int executingGrade) : _name(name), _isSigned(false), _signingGrade(signingGrade), _executingGrade(executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
		throw GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw GradeTooLowException();
	std::cout << "Form's Parametrized Constructor Called!" << std::endl;
}

Form::Form(const Form& obj) : _name(obj._name), _isSigned(obj._isSigned), _signingGrade(obj._signingGrade), _executingGrade(obj._executingGrade)
{
	std::cout << "Form's Copy Constructor Called!" << std::endl;
}

Form& Form::operator=(const Form& obj)
{
	if (this == &obj)
		return *this;
	this->_isSigned = obj._isSigned;
	std::cout << "Form's Copy Assignment Operator Called!" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form's Destructor Called!" << std::endl;
}

const std::string& Form::getName() const
{
	return _name;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

int Form::getSigningGrade() const
{
	return _signingGrade;
}

int Form::getExecutingGrade() const
{
	return _executingGrade;
}

void Form::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signingGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const Form& obj)
{
	out << "Form [ name: " << obj.getName()
		<< " | signed: " << (obj.getIsSigned() ? "yes" : "no")
		<< " | signing grade: " << obj.getSigningGrade()
		<< " | executing grade: " << obj.getExecutingGrade()
		<< " ]";
		return out;
}