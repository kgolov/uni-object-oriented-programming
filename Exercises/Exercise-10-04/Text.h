#ifndef __TEXT_H
#define __TEXT_H

#include "Line.h"

const int EMPTY_TEXT = -1;

class Text {
	Line* lines;
	int top;
	int size;

	bool isFull() const;
	void resize();

public:
	Text();
	~Text();
	Text(const Line& toAdd);
	Text(const Text& toCopy);
	Text& operator=(const Text& toCopy);

	// Getters
	Line getLine(int index) const;
	Line operator[](int index) const;
	bool isEmpty() const;
	void print() const;

	// Setters
	void add(const Line& toAdd);
	Text& operator+=(const Line& toAdd);
};

#endif