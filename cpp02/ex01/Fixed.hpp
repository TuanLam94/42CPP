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
		Fixed(const  int num);
		Fixed(const float num);
		Fixed &operator = (const Fixed& src);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

};

std::ostream& operator << (std::ostream& os, const Fixed& i);

#endif