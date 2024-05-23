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
	_value = static_cast<int>(roundf(num * (1 << _fract_bits)));
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

bool Fixed::operator > (const Fixed& src) const
{
	std::cout << "> operator called\n";
	return (this->_value > src._value);
}

bool Fixed::operator < (const Fixed& src) const
{
	std::cout << "< operator called\n";
	return (this->_value < src._value);
}

bool Fixed::operator >= (const Fixed& src) const
{
	std::cout << ">= operator called\n";
	return (this->_value >= src._value);
}

bool Fixed::operator <= (const Fixed& src) const
{
	std::cout << "<= operator called\n";
	return (this->_value <= src._value);
}

bool Fixed::operator == (const Fixed& src) const
{
	std::cout << "== operator called\n";
	return (this->_value == src._value);
}

bool Fixed::operator != (const Fixed& src) const
{
	std::cout << "!= operator called\n";
	return (this->_value != src._value);
}

Fixed Fixed::operator + (const Fixed& src) const
{
	std::cout << "+ operator called\n";
	Fixed result;
	result._value = this->_value + src._value;
	return result;
}

Fixed Fixed::operator - (const Fixed& src) const
{
	std::cout << "- operator called\n";
	Fixed result;
	result._value = this->_value - src._value;
	return result;
}

Fixed Fixed::operator * (const Fixed& src) const
{
	std::cout << "* operator called\n";
	Fixed result;
	result._value = (this->_value * src._value) >> _fract_bits;
	return result;
}

Fixed Fixed::operator / (const Fixed& src) const
{
	std::cout << "/ operator called\n";
	Fixed result;
	result._value = (this->_value << _fract_bits) / src._value;
	return result;
}

Fixed Fixed::operator ++()
{
	std::cout << "pre++ operator called\n";
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	std::cout << "post++ operator called\n";
	Fixed temp = *this;
	this->_value += 1;
	return (temp);
}

Fixed Fixed::operator --()
{
	std::cout << "pre-- operator called\n";
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator --(int)
{
	std::cout << "post-- operator called\n";
	Fixed temp = *this;
	this->_value -= 1;
	return (temp);
}

Fixed& Fixed::min(Fixed& first, Fixed& second)
{
	return (first._value < second._value) ? first : second;
}

const Fixed& Fixed::min(const Fixed& first, const Fixed& second)
{
	return (first._value < second._value) ? first : second;
}

Fixed& Fixed::max(Fixed& first, Fixed& second)
{
	return (first._value > second._value) ? first : second;
}

const Fixed& Fixed::max(const Fixed& first, const Fixed& second)
{
	return (first._value > second._value) ? first : second;
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

std::ostream& operator << (std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}