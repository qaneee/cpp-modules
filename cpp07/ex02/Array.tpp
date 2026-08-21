template <typename T>
Array<T>::Array() : arr(NULL), arr_size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : arr_size(n)
{
	arr = new T[n];
	for (unsigned int i = 0; i < n; i++)
	{
		arr[i] = T();
	}
}

template <typename T>
Array<T>::Array(const Array &obj) : arr(NULL), arr_size(0)
{
	*this = obj;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
		return *this;
	delete[] arr;
	arr_size = obj.arr_size;
	arr = new T[arr_size];
	for (unsigned int i = 0; i < arr_size; i++)
	{
		arr[i] = obj.arr[i];
	}
	return *this;
}

template <typename T>
unsigned int Array<T>::size() const
{
	return arr_size;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx)
{
	if (idx >= arr_size)
		throw OutOfBounds();
	return arr[idx];
}

template <typename T>
const T& Array<T>::operator[](unsigned int idx) const
{
	if (idx >= arr_size)
		throw OutOfBounds();
	return arr[idx];
}

template <typename T>
Array<T>::~Array()
{
	delete [] arr;
}