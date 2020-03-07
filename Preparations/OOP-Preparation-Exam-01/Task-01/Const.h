#pragma once
#include "Expression.h"

class Const : public Expression {
public:
	Const(const double newVal = 0);

	const double value() const override;
	void print() const override;
};