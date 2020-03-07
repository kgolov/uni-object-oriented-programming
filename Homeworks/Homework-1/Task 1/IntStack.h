#ifndef __INTSTACK_H
#define __INTSTACK_H

// A constant index which defines an empty stack
int const EMPTY_STACK = -1;

class IntStack {
private:
	int* elements;
	int top;
	int size;

	bool isFull() const;
	void resize();

public:
	// Constructors and destructors
	IntStack();
	~IntStack();
	IntStack(const IntStack& toCopy);
	IntStack& operator=(const IntStack& toCopy);

	// Getters
	bool isEmpty() const;
	int peek() const;

	// Setters
	void push(int number);
	int pop();

	// Other member functions
	void print() const;

	// Friend functions
	friend IntStack sortStack(IntStack toSort);
};

#endif