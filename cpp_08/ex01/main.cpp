#include "Span.hpp"

/*int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl; std::cout << sp.longestSpan() << std::endl;
	return 0;
}*/

void run_test(const char* name, void (*test_func)())
{
	std::cout << "\n=== " << name << " ===" << std::endl;
	try
	{
		test_func();
	}
	catch (const std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
}

void perform_large_test(unsigned int size)
{
	std::cout << "Running test with " << size << " elements..." << std::endl;

	Span sp(size);
	std::vector<int> data;
	for (unsigned int i = 0; i < size; ++i)
	{
		data.push_back(std::rand());
	}

	sp.addRange(data.begin(), data.end());

	std::sort(data.begin(), data.end());
	int expected = data.back() - data.front();

	if (sp.longestSpan() == expected)
		std::cout << "Longest span OK" << std::endl;
	else
		std::cout << "Longest span FAIL" << std::endl;
}

void test_capacity()
{
	Span sp(2);
	sp.addNumber(1);
	sp.addNumber(2);
	sp.addNumber(3);
}

void test_large_10k() { perform_large_test(10000); }
void test_large_100k() { perform_large_test(100000); }

void test_basic()
{
	Span sp(5);
	int arr[] = {6, 3, 17, 9, 11};
	sp.addRange(arr, arr + 5);
	std::cout << "Shortest: " << sp.shortestSpan() 
				<< " | Longest: " << sp.longestSpan() << std::endl;
}

int main()
{
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	run_test("Capacity/Exceptions", test_capacity);
	run_test("Large Dataset (10k)", test_large_10k);
	run_test("Large Dataset (100k)", test_large_100k);
	run_test("Basic Operations", test_basic);

	return 0;
}