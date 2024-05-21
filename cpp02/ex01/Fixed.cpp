#include "Fixed.hpp"

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called\n";
	_value = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called\n";
	_value = static_cast<int>(num * (1 << _fract_bits));
}

Fixed::Fixed(const Fixed& copy)
{
	*this = copy;
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator = (const Fixed& src)
{
	// if (this != &src)
	// 	this->_value = src.getRawBits();
	if (this != &src)
		this->_value = src._value;
	std::cout << "Copy assignment operator called\n";
	return *this;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(_value) / (1 << _fract_bits));
}
		
int Fixed::toInt(void) const
{
	return (_value >> _fract_bits);
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
	this->_value = raw;
	std::cout << "setRawBits member function called\n";
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}