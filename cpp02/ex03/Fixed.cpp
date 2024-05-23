#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {}

Fixed::Fixed(const int num)
{
	_value = num << _fract_bits;
}

Fixed::Fixed(const float num)
{
	_value = static_cast<int>(roundf(num * (1 << _fract_bits)));
}

Fixed::Fixed(const Fixed& copy) : _value(copy._value) {}

Fixed &Fixed::operator = (const Fixed& src)
{
	if (this != &src)
		_value = src._value;
	return *this;
}

bool Fixed::operator > (const Fixed& src) const
{
	return (this->_value > src._value);
}

bool Fixed::operator < (const Fixed& src) const
{
	return (this->_value < src._value);
}

bool Fixed::operator >= (const Fixed& src) const
{
	return (this->_value >= src._value);
}

bool Fixed::operator <= (const Fixed& src) const
{
	return (this->_value <= src._value);
}

bool Fixed::operator == (const Fixed& src) const
{
	return (this->_value == src._value);
}

bool Fixed::operator != (const Fixed& src) const
{
	return !(*this == src);
}

Fixed Fixed::operator + (const Fixed& src) const
{
    return Fixed(this->toFloat() + src.toFloat());
}

Fixed Fixed::operator - (const Fixed& src) const
{
    return Fixed(this->toFloat() - src.toFloat());
}

Fixed Fixed::operator * (const Fixed& src) const
{
    return Fixed(this->toFloat() * src.toFloat());
}

Fixed Fixed::operator / (const Fixed& src) const
{
    return Fixed(this->toFloat() / src.toFloat());
}

Fixed Fixed::operator ++()
{
	this->_value += 1;
	return (*this);
}

Fixed Fixed::operator ++(int)
{
	Fixed temp = *this;
	this->_value += 1;
	return (temp);
}

Fixed Fixed::operator --()
{
	this->_value -= 1;
	return (*this);
}

Fixed Fixed::operator --(int)
{
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
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
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
}

std::ostream& operator << (std::ostream& os, const Fixed& fixed) {
	return (os << fixed.toFloat());
}