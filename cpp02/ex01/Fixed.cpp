#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed()
{
	this->number = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const int_num)
{
	std::cout << "Int constructor called" << std::endl;
	this->number = int_num << fract_bits;
}

Fixed::Fixed(float const float_num)
{
	std::cout << "Float constructor called" << std::endl;
	this->number = roundf(float_num * (1 << fract_bits));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->number = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return number;
}

void Fixed::setRawBits(int const raw)
{
	number = raw;
}

float Fixed::toFloat( void ) const
{
	return (float)number / (float)(1 << fract_bits);
}

int Fixed::toInt( void ) const
{
	return (number >> fract_bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}