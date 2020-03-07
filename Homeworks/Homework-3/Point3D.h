#pragma once

#include "Point2D.h"

class Point3D : public Point2D {
	double z;

public:
	Point3D();
	Point3D(const double x, const double y, const double z = 0);
	Point3D(const Point2D& point, const double z = 0);

	const double getZ() const { return z; }

	const double getDistanceTo(const Point3D& point) const;

	void print() const override;
};