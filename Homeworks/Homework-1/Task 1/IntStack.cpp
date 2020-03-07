#include <iostream>
#include "IntStack.h"

// Swaps two integers. Needed for sorting functions
void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

IntStack::IntStack() {
	size = 1;
	elements = new int[size];
	top = EMPTY_STACK;
}

IntStack::~IntStack() {
	delete[] elements;
}

// Copy constructor
IntStack::IntStack(const IntStack& toCopy) {
	size = toCopy.size;
	elements = new int[size];
	top = toCopy.top;

	for (int i = 0; i <= top; i++) {
		elements[i] = toCopy.elements[i];
	}
}

IntStack& IntStack::operator=(const IntStack& toCopy) {
	if (this != &toCopy) {
		delete[] elements;

		size = toCopy.size;
		elements = new int[size];
		top = toCopy.top;

		for (int i = 0; i <= top; i++) {
			elements[i] = toCopy.elements[i];
		}
	}

	return *this;
}

bool IntStack::isEmpty() const {
	return top == EMPTY_STACK;
}

bool IntStack::isFull() const {
	return top >= size - 1;
}

int IntStack::peek() const {
	if (isEmpty()) {
		std::cerr << "Error: an attempt to peek into an empty stack!" << std::endl;
		return 0;
	}

	return elements[top];
}

int IntStack::pop() {
	if (isEmpty()) {
		std::cerr << "Error: an attempt to pop from an empty stack!" << std::endl;
		return 0;
	}

	return elements[top--];
}

void IntStack::resize() {
	size *= 2;
	
	int* newElements = new int[size];

	for (int i = 0; i <= top; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

void IntStack::push(int number) {
	if (isFull()) {
		resize();
	}

	elements[++top] = number;
}

// Prints all elements of the stack from the top to the bottom
void IntStack::print() const {
	if (isEmpty()) {
		std::cerr << "Error: an attempt to print an empty stack!" << std::endl;
		return;
	}

	for (int i = top; i >= 0; i--) {
		std::cout << elements[i] << ' ';
	}
}

// Sorts a stack using the bubble sort algorithm
// Declared as a friend function to have access to the stack fields
IntStack sortStack(IntStack toSort) {
	IntStack sorted(toSort);

	// Use the bubble sort metod for sorting
	for (int i = 0; i < sorted.top; i++) {
		for (int j = 0; j < sorted.top - i; j++) {
			if (sorted.elements[j] > sorted.elements[j + 1]) {
				swap(sorted.elements[j], sorted.elements[j + 1]);
			}
		}
	}

	return sorted;
}