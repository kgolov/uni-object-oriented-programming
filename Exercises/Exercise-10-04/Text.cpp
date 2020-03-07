#include <iostream>
#include "Text.h"

Text::Text() {
	size = 1;
	lines = new Line[size];
	top = EMPTY_TEXT;
}

Text::~Text() {
	delete[] lines;
}

Text::Text(const Line& toAdd) {
	size = 1;
	lines = new Line[size];
	top = EMPTY_TEXT;

	add(toAdd);
}

Text::Text(const Text& toCopy) {
	size = toCopy.size;
	top = toCopy.top;
	lines = new Line[size];

	for (int i = 0; i <= top; i++) {
		lines[i] = toCopy.lines[i];
	}
}

Text& Text::operator=(const Text& toCopy) {
	if (this != &toCopy) {
		size = toCopy.size;
		top = toCopy.top;

		delete[] lines;
		lines = new Line[size];

		for (int i = 0; i <= top; i++) {
			lines[i] = toCopy.lines[i];
		}
	}
	return *this;
}

Line Text::getLine(int index) const {
	if (index < 0 || index > top) {
		return Line();
	}

	return lines[index];
}

Line Text::operator[](int index) const {
	return getLine(index);
}

bool Text::isFull() const {
	return top >= size - 1;
}

bool Text::isEmpty() const {
	return top == EMPTY_TEXT;
}

void Text::resize() {
	size *= 2;

	Line* newLines = new Line[size];

	for (int i = 0; i <= top; i++) {
		newLines[i] = lines[i];
	}

	delete[] lines;
	lines = newLines;
}

void Text::print() const {
	if (isEmpty()) {
		std::cout << "Empty text." << std::endl;
		return;
	}

	for (int i = 0; i <= top; i++) {
		std::cout << getLine(i).value() << std::endl;
	}
}

void Text::add(const Line& toAdd) {
	if (isFull()) {
		resize();
	}

	lines[++top] = toAdd;
}

Text& Text::operator+=(const Line& toAdd) {
	add(toAdd);
	return *this;
}