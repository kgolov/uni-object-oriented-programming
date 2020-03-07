#pragma once

class Expression {
protected:
	double val;
	Expression(const double newVal = 0);

public:
	virtual const double value() const = 0;
	virtual void print() const = 0;
};