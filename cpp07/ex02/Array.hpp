#pragma once

#include <iostream>
#include <exception>
#include <cstdlib>

template <typename T>
class Array
{
	private:
		T *arr;
		unsigned int arr_size;

	public:
		Array();
		Array(unsigned int n);
		Array(const Array &obj);
		Array& operator=(const Array &obj);
		~Array();

		T &operator[](unsigned int idx);
		const T &operator[](unsigned int idx) const;

		class OutOfBounds : public std::exception
		{
			const char* what() const throw()
			{
				return "Index is Out of Bounds";
			}
		};

		unsigned int size() const;
};

#include "Array.tpp"