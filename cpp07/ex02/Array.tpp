#include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(new T()), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(const Array& copy) : _array(new T[copy._size]), _size(copy._size) 
{
	for (size_t i = 0; i < _size; i++) {
		_array[i] = copy._array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator = (const Array& rhs)
{
	if (this != rhs) {
		delete [] _array;
		_size = rhs._size;
		_array = new T[_size];
		for (size_t i = 0; i < _size; i++) {
			_array[i] = rhs._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete [] _array;
}

template <typename T>
size_t Array<T>::size() const
{
	return (_size);
}

template <typename T>
const T& Array<T>::operator [] (size_t index) const
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}

template <typename T>
T& Array<T>::operator [] (size_t index) 
{
	if (index >= _size)
		throw OutOfBoundsException();
	return _array[index];
}