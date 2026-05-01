#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(int const int_num);
		Fixed(float const float_num);
		Fixed(const Fixed &obj);
		Fixed& operator=(const Fixed &obj);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
		
	private:
		int number;
		static const int fract_bits;
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif