#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T> class Array
{
	private:
		T* _array;
		size_t _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		Array &operator = (const Array& rhs);
		~Array();
		size_t size() const;
		const T& operator [] (size_t index) const;
		T& operator [] (size_t index);

		//Exception
		class OutOfBoundsException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Index is out of array bounds !";
				}
		};
};

template <typename T>
std::ostream& operator << (std::ostream& os, const Array<T>& arr)
{
	for (size_t i = 0; i < arr.size(); i++) {
		os << "array [" << i << "] = " << arr[i] << std::endl;
	}
	return os;
}

#include "Array.tpp"

#endif