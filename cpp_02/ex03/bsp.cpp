#include "Point.hpp"

static Fixed cross_product(Point const &o, Point const &a, Point const &b)
{
	return (a.getX() - o.getX()) * (b.getY() - o.getY()) - (a.getY() - o.getY()) * (b.getX() - o.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = cross_product(a, b, point);
	Fixed d2 = cross_product(b, c, point);
	Fixed d3 = cross_product(c, a, point);
	Fixed zero(0);

	return ((d1 > zero && d2 > zero && d3 > zero) || (d1 < zero && d2 < zero && d3 < zero));
}