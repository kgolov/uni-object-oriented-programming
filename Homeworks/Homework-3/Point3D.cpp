#include "Point3D.h"
#include <cmath>
#include <iostream>

Point3D::Point3D() : Point2D(), z(0) {

}

Point3D::Point3D(const double x, const double y, const double z) :
	Point2D(x, y), z(z) {

}

Point3D::Point3D(const Point2D& point, const double z) : Point2D(point), z(z) {

}

const double Point3D::getDistanceTo(const Point3D& point) const {
	double xDiff2 = pow(getX() - point.getX(), 2);
	double yDiff2 = pow(getY() - point.getY(), 2);
	double zDiff2 = pow(getZ() - point.getZ(), 2);

	return sqrt(xDiff2 + yDiff2 + zDiff2);
}

void Point3D::print() const {
	std::cout << "(" << getX() << ", " << getY() << ", " << getZ() << ")";
}