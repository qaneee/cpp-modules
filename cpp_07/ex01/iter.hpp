#pragma once
#include <iostream>
#include <string>

template <typename T, typename F>
void iter(T *arr, int const arr_size, F func)
{
	for(int i = 0; i < arr_size; i++)
		func(arr[i]);
}

template <typename T>
void print(T const &x)
{
	std::cout << x << " ";
}
