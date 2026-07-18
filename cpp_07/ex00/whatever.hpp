#pragma once

template <typename T>
void swap(T &a, T &b)
{
	T t = a;
	a = b;
	b = t;
}

template <typename T> 
T max(T const &a , T const &b)
{
	if (a > b)
		return a;
	return b;
}

template <typename T> 
T min(T const &a , T const &b)
{
	if (a < b)
		return a;
	return b;
}