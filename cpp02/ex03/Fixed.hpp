#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

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

		bool operator > (const Fixed& src) const;
		bool operator < (const Fixed& src) const;
		bool operator >= (const Fixed& src) const;
		bool operator <= (const Fixed& src) const;
		bool operator == (const Fixed& src) const;
		bool operator != (const Fixed& src) const;

		Fixed operator + (const Fixed& src) const;
		Fixed operator - (const Fixed& src) const;
		Fixed operator * (const Fixed& src) const;
		Fixed operator / (const Fixed& src) const;

		Fixed operator ++();
		Fixed operator ++(int);
		Fixed operator --();
		Fixed operator --(int);

		static Fixed& min(Fixed& first, Fixed& second);
		static const Fixed& min(const Fixed& first, const Fixed& second);
		static Fixed& max(Fixed& first, Fixed& second);
		static const Fixed& max(const Fixed& first, const Fixed& second);

		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator << (std::ostream& os, const Fixed& i);

#endif