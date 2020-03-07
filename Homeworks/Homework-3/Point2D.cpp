#include "Point2D.h"
#include <cmath>
#include <iostream>

Point2D::Point2D() : x(0), y(0) {

}

Point2D::Point2D(const double x, const double y) : x(x), y(y) {

}

const double Point2D::getDistanceTo(const Point2D& point) const {
	double xDiff2 = pow(getX() - point.getX(), 2);
	double yDiff2 = pow(getY() - point.getY(), 2);

	return sqrt(xDiff2 + yDiff2);
}

void Point2D::print() const {
	std::cout << "(" << getX() << ", " << getY() << ")";
}