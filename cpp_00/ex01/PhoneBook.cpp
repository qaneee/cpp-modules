#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->contact_count = 0;
	this->current_contact = 0;
}

PhoneBook::~PhoneBook()
{
}

int PhoneBook::add_contact(void)
{
	contacts[current_contact].getFullContact();
	current_contact = (current_contact + 1) % MAX_CONTACTS;
	if (contact_count < MAX_CONTACTS)
		contact_count++;
	return (contact_count);
}

static bool is_valid_index(const std::string &idx, int count)
{
	if (idx.length() != 1)
		return false;
	int i = idx[0] - '0';
	return (std::isdigit(idx[0]) && i >= 0 && i < count);
}

void PhoneBook::search_contact()
{
	if (contact_count == 0)
	{
		std::cout << "PhoneBook is empty!" << std::endl;
	}
	std::cout << std::right << "|"<< std::setw(10) << "Index"
			<< "|" << std::setw(10) << "First Name"
			<< "|" << std::setw(10) << "Last Name"
			<< "|" << std::setw(10) << "Nickname"
			<< "|" << std::endl;
	int i = 0;
	while (i < contact_count)
	{
		contacts[i].printContact(i);
		i++;
	}
	std::cout << "Enter index: ";
	std::string idx;
	if (!std::getline(std::cin, idx))
	{
		std::cout << std::endl << EXIT_MSG << std::endl;
		std::exit(1);
	}
	if (!is_valid_index(idx, contact_count))
		std::cout << "Invalid index! Please try again!" << std::endl;
	else
		contacts[idx[0] - '0'].printInfo();
}