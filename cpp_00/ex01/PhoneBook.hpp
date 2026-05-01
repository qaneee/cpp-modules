#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Contact.hpp"

#define MAX_CONTACTS 8

class PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		contact_count;
		int		current_contact;
	public:
		PhoneBook();
		int add_contact(void);
		void search_contact();
		~PhoneBook();
};

#endif