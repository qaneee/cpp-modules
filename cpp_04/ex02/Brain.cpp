#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Default Constructor Called (Brain)!" << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = "Default Idea!";
}

Brain::Brain(const Brain &obj)
{
	std::cout << "Copy Constructor Called (Brain)!" << std::endl;
	*this = obj;
}

Brain& Brain::operator=(const Brain &obj)
{
	std::cout << "Copy Assignment Operator (Brain)!" << std::endl;
	if (this != &obj)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = obj.ideas[i];
	}
	return *this;
}

Brain::~Brain()
{
	std::cout << "Destructor (Brain)!" << std::endl;
}

void Brain::setIdea(int index, const std::string &idea)
{
	if (index < 0 || index > 99)
		return ;
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index > 99)
		return "";
	return ideas[index];
}