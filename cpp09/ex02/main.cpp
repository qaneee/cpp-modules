#include "PmergeMe.hpp"

int main(int argc, char** argv)
{
	if (argc == 1)
	{
		std::cerr << "Error\n";
		return 1;
	}
	try
	{
		PmergeMe pm(argv);
		pm.startAlgorithm();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return 1;
	}
	return 0;
}
