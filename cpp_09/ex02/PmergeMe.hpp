#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <stdexcept>
#include <ctime>
#include <cstddef>
#include <limits>
#include <iomanip>
#include <algorithm>
#include <utility>
class PmergeMe
{
	private:
		std::vector<int> vect;
		std::deque<int>  deq;

		void sort_vect(std::vector<int> &mainChain);
		void sort_deq(std::deque<int> &mainChain);

		std::vector<size_t> jacobsthalOrder(size_t n) const;

		void printVector(const std::string &label, const std::vector<int> &v) const;
		void printTime(const std::string &containerName, size_t count, double microseconds) const;

	public:
		PmergeMe();
		PmergeMe(char **argv);
		PmergeMe(const PmergeMe &obj);
		PmergeMe& operator=(const PmergeMe &obj);
		~PmergeMe();

		void startAlgorithm();
};

#endif