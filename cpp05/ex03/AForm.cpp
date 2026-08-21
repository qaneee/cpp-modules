#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _signingGrade(20), _executingGrade(15)
{
	std::cout << "AForm's Default Constructor Called!" << std::endl;
}

AForm::AForm(const std::string& name, int signingGrade, int executingGrade) : _name(name), _isSigned(false), _signingGrade(signingGrade), _executingGrade(executingGrade)
{
	if (signingGrade < 1 || executingGrade < 1)
		throw GradeTooHighException();
	if (signingGrade > 150 || executingGrade > 150)
		throw GradeTooLowException();
	std::cout << "AForm's Parametrized Constructor Called!" << std::endl;
}

AForm::AForm(const AForm& obj) : _name(obj._name), _isSigned(obj._isSigned), _signingGrade(obj._signingGrade), _executingGrade(obj._executingGrade)
{
	std::cout << "AForm's Copy Constructor Called!" << std::endl;
}

AForm& AForm::operator=(const AForm& obj)
{
	if (this == &obj)
		return *this;
	this->_isSigned = obj._isSigned;
	std::cout << "AForm's Copy Assignment Operator Called!" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm's Destructor Called!" << std::endl;
}

const std::string& AForm::getName() const
{
	return _name;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getSigningGrade() const
{
	return _signingGrade;
}

int AForm::getExecutingGrade() const
{
	return _executingGrade;
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > _signingGrade)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream& operator<<(std::ostream& out, const AForm& obj)
{
	out << "AForm [ name: " << obj.getName()
		<< " | signed: " << (obj.getIsSigned() ? "yes" : "no")
		<< " | signing grade: " << obj.getSigningGrade()
		<< " | executing grade: " << obj.getExecutingGrade()
		<< " ]";
		return out;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!this->_isSigned)
		throw NotSignedException();

	if (executor.getGrade() > this->_executingGrade)
		throw GradeTooLowException();
}