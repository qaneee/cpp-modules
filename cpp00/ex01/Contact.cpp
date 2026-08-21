#include "Contact.hpp"

Contact::Contact()
{
	this->first_name = "";
	this->last_name = "";
	this->phone_number = "";
	this->nickname = "";
	this->darkest_secret = "";
}
Contact::Contact(std::string FName, std::string LName, std::string NName, std::string PNumber, std::string DSecret)
{
	this->first_name = FName;
	this->last_name = LName;
	this->nickname = NName;
	this->phone_number = PNumber;
	this->darkest_secret = DSecret;
}

Contact::~Contact()
{
}

static void get_contact_helper(const std::string &field_name, std::string &field)
{
	do {
		std::cout << field_name;
		if (!std::getline(std::cin, field))
		{
			std::cout << std::endl << EXIT_MSG << std::endl;
			std::exit(1);
		}
		if (field.empty())
			std::cout << ERR_MSG1 << std::endl;
	} while (field.empty());
}

static bool valid_pn(const std::string &pn)
{
	for (int i = 0; i < (int)pn.length(); i++)
	{
		if (!isdigit(pn[i]))
			return false;
	}
	return true;
}

void Contact::getFullContact()
{
	get_contact_helper("First Name: ", first_name);
	get_contact_helper("Last Name: ", last_name);
	get_contact_helper("Nickname: ", nickname);
	do {
		get_contact_helper("Phone Number: ", phone_number);
		if (!valid_pn(phone_number))
		{
			std::cout << "Phone Number must contain only digits." <<std::endl;
		}
	} while (!valid_pn(phone_number));
	get_contact_helper("Darkest Secret: ", darkest_secret);
}

static std::string truncate_field(const std::string &s)
{
	if (s.length() > 10)
		return s.substr(0, 9) + ".";
	return s;
}

void Contact::printContact(int index) const
{
	std::cout << std::right << "|" << std::setw(10) << index
			<< "|" << std::setw(10) << truncate_field(first_name)
			<< "|" << std::setw(10) << truncate_field(last_name)
			<< "|" << std::setw(10) << truncate_field(nickname)
			<< "|" << std::endl;
}

void Contact::printInfo()
{
	std::cout << "First Name: " << first_name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}