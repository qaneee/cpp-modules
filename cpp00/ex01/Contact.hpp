#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

#define ERR_MSG1 "Provided string is empty!"
#define EXIT_MSG "Exiting..."

class Contact
{
	private:
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;
	public:
		Contact();
		Contact(std::string FName, std::string LName, std::string NName, std::string PNumber, std::string DSecret);
		~Contact();
		void getFullContact();
		void printContact(int index) const;
		void printInfo();
};

#endif