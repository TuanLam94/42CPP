#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
		int _value;
		static const int _fract_bits = 8; 
	public:
	Fixed();
	Fixed(const Fixed& copy);
	Fixed &operator = (const Fixed& src);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif