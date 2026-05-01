#include <iostream>
#include <iomanip>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

int main(void)
{
	PhoneBook pb;
	std::string picked_command;

	while (1)
	{
		std::cout << "Enter a command: ADD / SEARCH / EXIT:  ";
		if (!std::getline(std::cin, picked_command))
		{
			std::cout << std::endl << EXIT_MSG << std::endl;
			break ;
		}
		if (picked_command.empty())
			continue ;
		if (picked_command == "ADD")
		{
			if (!pb.add_contact())
			{
				std::cout << "Adding contact failed!" << std::endl;
				break ;
			}
			else
				std::cout << "Contact was added successfully!" << std::endl;
		}
		else if (picked_command == "SEARCH")
		{
			pb.search_contact();
		}
		else if (picked_command == "EXIT")
		{
			std::cout << EXIT_MSG << std::endl;
			break ;
		}
		else
		{
			std::cout << "Invalid command! Please try again!" << std::endl;
		}
	}
	return 0;
}
