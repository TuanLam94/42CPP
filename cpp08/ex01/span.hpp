#ifndef SPAN_HPP
#define SPAN_HPP

#include <algorithm>
#include <vector>
#include <exception>
#include <iostream>
#include <limits>

class Span
{
	private:
		std::vector<int> _array;
		int	_size;
		int _nbElements;
	public:
		Span(unsigned int n);
		Span(const Span& copy);
		Span &operator = (const Span& other);
		~Span();

		int getNbElements() const;
		int getArrayI(int i) const;

		void addNumber(int x);
		int shortestSpan();
		int longestSpan();

		//Exception
		class ArrayIsFullException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Array is full !";
				}
		};

		class NotEnoughIntException : public std::exception
		{
			public:
				const char *what() const throw()
				{
					return "Not enough numbers in array !";
				}
		};
};

std::ostream& operator << (std::ostream& os, const Span& span);

#endif