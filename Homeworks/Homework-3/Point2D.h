#pragma once

class Point2D {
	double x;
	double y;

public:
	Point2D();
	Point2D(const double x, const double y);

	const double getX() const { return x; }
	const double getY() const { return y; }

	const double getDistanceTo(const Point2D& point) const;

	virtual void print() const;
};