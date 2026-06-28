#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) , target("default")
{
	std::cout << "ShrubberyCreationForm's Default Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& tg) : AForm("ShrubberyCreationForm", 145, 137) , target(tg)
{
	std::cout << "ShrubberyCreationForm's Parameritrized Constructor Called!" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& obj) : AForm(obj), target(obj.target)
{
	std::cout << "ShrubberyCreationForm's Copy Constructor Called!" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& obj)
{
	if (this == &obj)
		return *this;
	AForm::operator=(obj);
	std::cout << "ShrubberyCreationForm's Copy Assignment Operator Called!" << std::endl;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm's Destructor Called!" << std::endl;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	AForm::execute(executor);
	std::ofstream file((target + "_shrubbery").c_str());
	if (!file.is_open())
		std::cerr << "Cannot open file!" << std::endl;

	file <<
"              &&& &&  & &&\n"
"          && &\\/&\\|& ()|/ @, &&\n"
"          &\\/(/&/&||/& /_/)_&/_&\n"
"       &() &\\/&|()|/&\\/ '%\" & ()\n"
"      &_\\_&&_\\ |& |&&/&__%_/_& &&\n"
"    &&   && & &| &| /& & % ()& /&&\n"
"     ()&_---()&\\&\\|&&-&&--%---()~\n"
"         &&     \\|||\n"
"                 |||\n"
"                 |||\n"
"                 |||\n"
"           , -=-~  .-^- _\n";

	file.close();
}