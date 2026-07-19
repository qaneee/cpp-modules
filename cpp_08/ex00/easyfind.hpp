#pragma once

#include <iostream>
#include <algorithm>
#include <vector>

template <typename T>
typename T::iterator easyfind(T& container, int num)
{
	typename T::iterator it = std::find(container.begin(), container.end(), num);
	if (it == container.end())
	{
		std::cerr << "Error: Element " << num << " not found in container." << std::endl;
	}
	return it;
}