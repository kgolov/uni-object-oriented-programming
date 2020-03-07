#pragma once
#include "Expression.h"

class Var : public Expression {
protected:
	char* name = nullptr;

public:
	Var(const double newVal = 0, const char* newName = "");
	~Var();
	Var(const Var& toCopy);
	Var& operator=(const Var& toCopy);

	const double value() const override;
	void print() const override;
	void setValue(const double newVal);
};