#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const Fixed& copy)
{
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed &Fixed::operator = (const Fixed& src)
{
	std::cout << "Copy assignment operator called\n";
	if (this != &src)
		this->_value = src.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called\n";
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	this->_value = raw;
}