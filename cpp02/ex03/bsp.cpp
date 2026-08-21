#include "Point.hpp"

static Fixed triangle_area(Point const &o, Point const &a, Point const &b)
{
	Fixed result = (a.getX() - o.getX()) * (b.getY() - o.getY())
						- (a.getY() - o.getY()) * (b.getX() - o.getX());

	if (result < Fixed(0))
		result = Fixed(0) - result;
	return result;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed total = triangle_area(a, b, c);
	Fixed s1 = triangle_area(point, a, b);
	Fixed s2 = triangle_area(point, b, c);
	Fixed s3 = triangle_area(point, c, a);

	if (s1 == Fixed(0) || s2 == Fixed(0) || s3 == Fixed(0))
		return false;

	return (s1 + s2 + s3) == total;
}