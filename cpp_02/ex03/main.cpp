#include "Point.hpp"

int main()
{
	Point a(0, 0), b(10, 0), c(0, 10);
	std::cout << (bsp(a, b, c, Point(2, 2))   ? "PASS" : "FAIL") << " inside\n";
	std::cout << (bsp(a, b, c, Point(8, 8))   ? "FAIL" : "PASS") << " outside\n";
	std::cout << (bsp(a, b, c, Point(5, 0))   ? "FAIL" : "PASS") << " on edge\n";
	std::cout << (bsp(a, b, c, Point(0, 0))   ? "FAIL" : "PASS") << " on vertex\n";
	std::cout << (bsp(a, b, c, Point(20, 20)) ? "FAIL" : "PASS") << " far outside\n";

	std::cout << (bsp(a, b, c, Point(10, 0))  ? "FAIL" : "PASS") << " on vertex b\n";
	std::cout << (bsp(a, b, c, Point(0, 10))  ? "FAIL" : "PASS") << " on vertex c\n";

	std::cout << (bsp(a, b, c, Point(5, 5))   ? "FAIL" : "PASS") << " on hypotenuse\n";
	std::cout << (bsp(a, b, c, Point(0, 5))   ? "FAIL" : "PASS") << " on left edge\n";

	Point a2(-5, -5), b2(5, -5), c2(0, 5);
	std::cout << (bsp(a2, b2, c2, Point(0, 0))  ? "PASS" : "FAIL") << " inside negative triangle\n";
	std::cout << (bsp(a2, b2, c2, Point(0, -4)) ? "PASS" : "FAIL") << " inside negative triangle 2\n";
	std::cout << (bsp(a2, b2, c2, Point(10, 0)) ? "FAIL" : "PASS") << " outside negative triangle\n";

	Point a3(0, 0), b3(1, 0), c3(0, 1);
	std::cout << (bsp(a3, b3, c3, Point(0.1f, 0.1f)) ? "PASS" : "FAIL") << " inside small triangle\n";
	std::cout << (bsp(a3, b3, c3, Point(0.9f, 0.9f)) ? "FAIL" : "PASS") << " outside small triangle\n";

	Point a4(0, 3), b4(-3, 0), c4(3, 0);
	std::cout << (bsp(a4, b4, c4, Point(0, 1))  ? "PASS" : "FAIL") << " center of symmetric triangle\n";
	std::cout << (bsp(a4, b4, c4, Point(0, 3))  ? "FAIL" : "PASS") << " vertex of symmetric triangle\n";
}
