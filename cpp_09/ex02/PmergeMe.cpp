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

	std::vector<bool> used(n + 1, false);
	size_t a = 0;
	size_t b = 1;
	while (b <= n)
	{
		if (!used[b])
		{
			order.push_back(b);
			used[b] = true;
		}
		size_t next = b + 2 * a;
		a = b;
		b = next;
	}

	for (size_t i = 1; i <= n; ++i)
	{
		if (!used[i])
			order.push_back(i);
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

static size_t binarySearchVect(const std::vector<int> &data, size_t rangeEnd, int value)
{
	size_t low = 0, high = rangeEnd;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (data[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

static size_t binarySearchDeq(const std::deque<int> &data, size_t rangeEnd, int value)
{
	size_t low = 0, high = rangeEnd;
	while (low < high)
	{
		size_t mid = low + (high - low) / 2;
		if (data[mid] < value)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

void PmergeMe::sort_vect(std::vector<int> &mainChain)
{
	if (mainChain.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::vector<int> chain;
	std::vector<int> tail;
	int leftover = 0;
	bool hasLeftover = false;

	size_t i = 0;
	for (; i + 1 < mainChain.size(); i += 2)
	{
		int first = mainChain[i];
		int second = mainChain[i + 1];
		if (first >= second)
		{
			chain.push_back(first);
			tail.push_back(second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			chain.push_back(second);
			tail.push_back(first);
			pairs.push_back(std::make_pair(second, first));
		}
	}

	if (i < mainChain.size())
	{
		leftover = mainChain[i];
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

		size_t high = binarySearchVect(chain, chain.size(), boundValue);
		size_t pos = binarySearchVect(chain, high, value);
		chain.insert(chain.begin() + pos, value);
	}

	if (hasLeftover)
	{
		size_t pos = binarySearchVect(chain, chain.size(), leftover);
		chain.insert(chain.begin() + pos, leftover);
	}

	mainChain.swap(chain);
}

void PmergeMe::sort_deq(std::deque<int> &mainChain)
{
	if (mainChain.size() <= 1)
		return;

	std::vector<std::pair<int, int> > pairs;
	std::deque<int> chain;
	std::deque<int> tail;
	int leftover = 0;
	bool hasLeftover = false;

	size_t i = 0;
	for (; i + 1 < mainChain.size(); i += 2)
	{
		int first = mainChain[i];
		int second = mainChain[i + 1];
		if (first >= second)
		{
			chain.push_back(first);
			tail.push_back(second);
			pairs.push_back(std::make_pair(first, second));
		}
		else
		{
			chain.push_back(second);
			tail.push_back(first);
			pairs.push_back(std::make_pair(second, first));
		}
	}

	if (i < mainChain.size())
	{
		leftover = mainChain[i];
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

		size_t high = binarySearchDeq(chain, chain.size(), boundValue);
		size_t pos = binarySearchDeq(chain, high, value);

		std::deque<int>::iterator insertIt = chain.begin();
		std::advance(insertIt, pos);
		chain.insert(insertIt, value);
	}

	if (hasLeftover)
	{
		size_t pos = binarySearchDeq(chain, chain.size(), leftover);
		std::deque<int>::iterator insertIt = chain.begin();
		std::advance(insertIt, pos);
		chain.insert(insertIt, leftover);
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
