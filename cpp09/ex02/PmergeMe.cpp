#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(char **argv)
{
	if (!argv)
		throw std::invalid_argument("Error");

	for (int i = 1; argv[i]; ++i)
	{
		std::string token(argv[i]);
		if (token.empty())
			throw std::invalid_argument("Error");

		unsigned long value = 0;
		for (size_t j = 0; j < token.size(); ++j)
		{
			char c = token[j];
			if (c < '0' || c > '9')
				throw std::invalid_argument("Error");
			value = value * 10 + static_cast<unsigned long>(c - '0');
			if (value > static_cast<unsigned long>(std::numeric_limits<int>::max()))
				throw std::invalid_argument("Error");
		}
		if (value == 0)
			throw std::invalid_argument("Error");

		vect.push_back(static_cast<int>(value));
		deq.push_back(static_cast<int>(value));
	}
}

PmergeMe::PmergeMe(const PmergeMe &obj)
{
	if (this != &obj)
	{
		vect = obj.vect;
		deq = obj.deq;
	}
}

PmergeMe& PmergeMe::operator=(const PmergeMe &obj)
{
	if (this != &obj)
	{
		vect = obj.vect;
		deq = obj.deq;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

std::vector<size_t> PmergeMe::jacobsthalOrder(size_t n) const
{
	std::vector<size_t> order;
	if (n == 0)
		return order;

	order.push_back(1);
	size_t prevJ = 1;
	size_t currJ = 1;

	while (currJ < n)
	{
		size_t nextJ = currJ + 2 * prevJ;
		size_t limit = std::min(nextJ, n);

		for (size_t i = limit; i > currJ; --i)
			order.push_back(i);

		prevJ = currJ;
		currJ = nextJ;
	}
	return order;
}

void PmergeMe::printVector(const std::string &label, const std::vector<int> &v) const
{
	if (!label.empty())
		std::cout << label;
	for (size_t i = 0; i < v.size(); ++i)
	{
		if (i > 0 || !label.empty())
			std::cout << ' ';
		std::cout << v[i];
	}
	std::cout << '\n';
}

void PmergeMe::printTime(const std::string &containerName, size_t count, double microseconds) const
{
	std::cout << "Time to process a range of " << count << " elements with " << containerName << " : ";
	std::cout << std::fixed << std::setprecision(5) << microseconds << " us\n";
}

void PmergeMe::sort_vect(std::vector<int> &mainChain)
{
	if (mainChain.size() <= 1)
		return;

	std::vector<int> chain;
	std::vector<int> tail;
	std::vector<std::pair<int, int> > pairs;
	int leftover = 0;
	bool hasLeftover = false;

	for (size_t i = 0; i + 1 < mainChain.size(); i += 2)
	{
		if (mainChain[i] >= mainChain[i + 1])
		{
			chain.push_back(mainChain[i]);
			tail.push_back(mainChain[i + 1]);
			pairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
		}
		else
		{
			chain.push_back(mainChain[i + 1]);
			tail.push_back(mainChain[i]);
			pairs.push_back(std::make_pair(mainChain[i + 1], mainChain[i]));
		}
	}
	if (mainChain.size() % 2 != 0)
	{
		leftover = mainChain.back();
		hasLeftover = true;
	}

	sort_vect(chain);

	std::vector<size_t> order = jacobsthalOrder(tail.size());
	for (size_t idx = 0; idx < order.size(); ++idx)
	{
		size_t tailIndex = order[idx] - 1;
		if (tailIndex >= tail.size())
			continue;

		int value = tail[tailIndex];
		int boundValue = pairs[tailIndex].first;

		std::vector<int>::iterator boundIt = std::find(chain.begin(), chain.end(), boundValue);
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), boundIt, value);

		chain.insert(pos, value);
	}
	if (hasLeftover)
	{
		std::vector<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);
		chain.insert(pos, leftover);
	}
	mainChain.swap(chain);
}

void PmergeMe::sort_deq(std::deque<int> &mainChain)
{
	if (mainChain.size() <= 1)
		return;

	std::deque<int> chain;
	std::deque<int> tail;
	std::vector<std::pair<int, int> > pairs;
	int leftover = 0;
	bool hasLeftover = false;

	for (size_t i = 0; i + 1 < mainChain.size(); i += 2)
	{
		if (mainChain[i] >= mainChain[i + 1])
		{
			chain.push_back(mainChain[i]);
			tail.push_back(mainChain[i + 1]);
			pairs.push_back(std::make_pair(mainChain[i], mainChain[i + 1]));
		}
		else
		{
			chain.push_back(mainChain[i + 1]);
			tail.push_back(mainChain[i]);
			pairs.push_back(std::make_pair(mainChain[i + 1], mainChain[i]));
		}
	}
	if (mainChain.size() % 2 != 0)
	{
		leftover = mainChain.back();
		hasLeftover = true;
	}

	sort_deq(chain);

	std::vector<size_t> order = jacobsthalOrder(tail.size());
	for (size_t idx = 0; idx < order.size(); ++idx)
	{
		size_t tailIndex = order[idx] - 1;
		if (tailIndex >= tail.size())
			continue;
	
		int value = tail[tailIndex];
		int boundValue = pairs[tailIndex].first;

		std::deque<int>::iterator boundIt = std::find(chain.begin(), chain.end(), boundValue);
		std::deque<int>::iterator pos = std::lower_bound(chain.begin(), boundIt, value);
		chain.insert(pos, value);
	}
	if (hasLeftover)
	{
		std::deque<int>::iterator pos = std::lower_bound(chain.begin(), chain.end(), leftover);
		chain.insert(pos, leftover);
	}
	mainChain.swap(chain);
}

void PmergeMe::startAlgorithm()
{
	std::cout << "Before: ";
	printVector("", vect);
	std::vector<int> vectorCopy = vect;
	std::deque<int> dequeCopy = deq;

	std::clock_t startVector = std::clock();
	sort_vect(vectorCopy);
	std::clock_t endVector = std::clock();

	std::clock_t startDeque = std::clock();
	sort_deq(dequeCopy);
	std::clock_t endDeque = std::clock();

	double timeVector = static_cast<double>(endVector - startVector) / CLOCKS_PER_SEC * 1000000.0;
	double timeDeque = static_cast<double>(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000.0;

	std::cout << "After: ";
	printVector("", vectorCopy);
	printTime("std::vector", vectorCopy.size(), timeVector);
	printTime("std::deque", dequeCopy.size(), timeDeque);
}
