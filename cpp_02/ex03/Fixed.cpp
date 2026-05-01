#include "Fixed.hpp"

const int Fixed::fract_bits = 8;

Fixed::Fixed()
{
	this->number = 0;
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &obj)
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = obj;
}

Fixed::Fixed(int const int_num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->number = int_num << fract_bits;
}

Fixed::Fixed(float const float_num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->number = roundf(float_num * (1 << fract_bits));
}

Fixed& Fixed::operator=(const Fixed& obj)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this == &obj)
		return *this;
	this->number = obj.getRawBits();
	return *this;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" <<std::endl;
	return number;
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << "setRawBits member function called" <<std::endl;
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

bool Fixed::operator>(const Fixed& obj) const
{
	return (this->number > obj.number);
}

bool Fixed::operator<(const Fixed& obj) const
{
	return (this->number < obj.number);
}

bool Fixed::operator>=(const Fixed& obj) const
{
	return (this->number >= obj.number);
}

bool Fixed::operator<=(const Fixed& obj) const
{
	return (this->number <= obj.number);
}

bool Fixed::operator==(const Fixed& obj) const
{
	return (this->number == obj.number);
}

bool Fixed::operator!=(const Fixed& obj) const
{
	return (this->number != obj.number);
}

Fixed &Fixed::min(Fixed& f1, Fixed& f2)
{
	if (f1.number < f2.number)
		return f1;
	return f2;
}

const Fixed &Fixed::min(const Fixed& f1, const Fixed& f2)
{
	if (f1.number < f2.number)
		return f1;
	return f2;
}

const Fixed &Fixed::max(const Fixed& f1, const Fixed& f2)
{
	if (f1.number < f2.number)
		return f2;
	return f1;
}

Fixed &Fixed::max(Fixed& f1, Fixed& f2)
{
	if (f1.number < f2.number)
		return f2;
	return f1;
}

Fixed Fixed::operator+(const Fixed& obj) const
{
	Fixed res;
	res.setRawBits(this->number + obj.number);
	return res;
}

Fixed Fixed::operator-(const Fixed& obj) const
{
	Fixed res;
	res.setRawBits(this->number - obj.number);
	return res;
}

Fixed Fixed::operator*(const Fixed& obj) const
{
	Fixed res;
	res.setRawBits((long long)this->number * obj.number >> fract_bits);
	return res;
}

Fixed Fixed::operator/(const Fixed &obj) const
{
	Fixed res;
	res.setRawBits(((long long)this->number << fract_bits) / obj.number);
	return res;
}

Fixed& Fixed::operator++()
{
	number++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed tmp = *this;
	number++;
	return tmp;
}

Fixed& Fixed::operator--()
{
	number--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed tmp = *this;
	number--;
	return tmp;
}