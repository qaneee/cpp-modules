#include "easyfind.hpp"
#include <vector>
#include <list>
#include <iostream>

int main()
{
	std::cout << "--- Vector ---" << std::endl;
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	std::vector<int>::iterator it = easyfind(v, 2);
	if (it != v.end())
		std::cout << "Found: " << *it << std::endl;

	it = easyfind(v, 0);
	if (it == v.end())
		std::cout << "Confirmed: 0 is not in vector." << std::endl;

	std::cout << "\n--- List ---" << std::endl;
	std::list<int> l;
	l.push_back(10);
	l.push_back(20);
	l.push_back(30);

	std::list<int>::iterator lit = easyfind(l, 10);
	if (lit != l.end())
		std::cout << "Found: " << *lit << std::endl;

	lit = easyfind(l, 99);
	if (lit == l.end())
		std::cout << "Confirmed: 99 is not in list." << std::endl;

	return 0;
}