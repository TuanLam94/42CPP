#include "span.hpp"

Span::Span(unsigned int n) : _size(n), _nbElements(0) {}

Span::Span(const Span& copy) : _array(copy._array), _size(copy._size), _nbElements(copy._nbElements) {}

Span& Span::operator = (const Span& rhs)
{
	if (this != &rhs) {
		_size = rhs._size;
		_nbElements = rhs._nbElements;
		_array = rhs._array;
		}
	return *this;
}

Span::~Span() {}

int Span::getNbElements() const
{
	return _nbElements;
}

int Span::getArrayI(int i) const
{
	return _array[i];
}

void Span::addNumber(int x)
{
	if (_nbElements == _size)
		throw ArrayIsFullException();
	_array.push_back(x);
	_nbElements++;
}

int Span::longestSpan()
{
	if (_nbElements < 2)
		throw NotEnoughIntException();

	int minElement = *std::min_element(_array.begin(), _array.end());
	int maxElement = *std::max_element(_array.begin(), _array.end());

	return maxElement - minElement;
}

int Span::shortestSpan()
{
	if (_nbElements < 2)
		throw NotEnoughIntException();
	
	std::vector<int> sorted = _array;
	std::sort(sorted.begin(), sorted.end());

	int res = std::numeric_limits<int>::max();
	for (int i = 1; i < _nbElements; i++) {
		int span = sorted[i] - sorted[i - 1];
		if (span < res)
			res = span;
	}

	return res;
}

std::ostream& operator << (std::ostream& os, const Span& span)
{
    for (int i = 0; i < span.getNbElements(); ++i) {
        os << span.getArrayI(i) << " ";
	}
	return os;
}
