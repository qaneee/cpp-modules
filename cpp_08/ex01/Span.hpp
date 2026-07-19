#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <ctime>
#include <exception>

class Span
{
	private:
		unsigned int N;
		std::vector<int> span;

	public:
		Span(unsigned int n);
		Span(const Span& obj);
		Span& operator=(const Span& obj);
		~Span();

		void addNumber(int n);
		int shortestSpan() const;
		int longestSpan() const;
		template <typename T>
		void addRange(T begin, T end);
};

template <typename T>
void Span::addRange(T begin, T end)
{
	if (span.size() + static_cast<size_t>(std::distance(begin, end)) > N)
		throw std::length_error("Span is full");
	span.insert(span.end(), begin, end);
}