#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::~Point() {}

Point &Point::operator=(const Point &obj)
{
	(void)obj;
	return *this;
}

Point::Point(const Point &obj) : x(obj.x), y(obj.y) {}

Point::Point(const float num1, const float num2) : x(num1), y(num2) {}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}