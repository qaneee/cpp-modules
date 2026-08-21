#include "Span.hpp"

Span::Span(unsigned int n) : N(n) {}

Span::Span(const Span& obj) : N(obj.N), span(obj.span) {}

Span& Span::operator=(const Span& obj)
{
	if (this != &obj)
	{
		N = obj.N;
		span = obj.span;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int n)
{
	if (span.size() >= N)
		throw std::length_error("Span is full");
	span.push_back(n);
}

int Span::shortestSpan() const
{
	if (span.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	std::vector<int> sorted(span);
	std::sort(sorted.begin(), sorted.end());

	int minDiff = INT_MAX;
	for (size_t i = 1; i < sorted.size(); ++i)
	{
		int diff = sorted[i] - sorted[i - 1];
		if (diff < minDiff)
			minDiff = diff;
	}
	return minDiff;
}

int Span::longestSpan() const
{
	if (span.size() < 2)
		throw std::length_error("Not enough numbers to find a span");

	int maximum = *std::max_element(span.begin(), span.end());
	int minimum = *std::min_element(span.begin(), span.end());
	return (maximum - minimum);
}
