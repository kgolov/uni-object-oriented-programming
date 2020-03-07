#include "Line.h"

Line::Line() {
	length = 0;
	text = new char[length + 1];
	text[0] = '\0';
}

Line::~Line() {
	delete[] text;
}

Line::Line(const char* str) {
	setValue(str);
}

Line::Line(const Line& toCopy) {
	setValue(toCopy.value());
}

Line& Line::operator=(const Line& toCopy) {
	if (this != &toCopy) {
		delete[] text;

		setValue(toCopy.value());
	}
	return *this;
}

const char Line::operator[](int index) const {
	if (index < 0 || index > length) {
		return '\0';
	}

	return text[index];
}

const char* Line::value() const {
	return text;
}

const size_t Line::size() const {
	return length;
}

void Line::setValue(const char* str) {
	for (length = 0; str[length] != '\0' && str[length] != '\n'; length++);

	text = new char[length + 1];

	// Copy all elements from the string up until the terminating zero or the new line
	for (size_t i = 0; i < length; i++) {
		text[i] = str[i];
	}

	// Add a terminating zero
	text[length] = '\0';
}

Line SplitLine(Line& toSplit, size_t index) {
	char* firstPart = new char[index + 1];

	for (size_t i = 0; i < index && toSplit[i] != '\0'; i++) {
		firstPart[i] = toSplit[i];
	}
	firstPart[index] = '\0';

	size_t secondSize = toSplit.size() - index + 1;
	char* secondPart = new char[secondSize];
	
	for (size_t i = 0; i < secondSize; i++) {
		secondPart[i] = toSplit[i + index];
	}

	Line toReturn(secondPart);
	delete[] secondPart;

	toSplit.setValue(firstPart);
	delete[] firstPart;

	return toReturn;
}

Line ConcatenateLines(const Line& line1, const Line& line2) {
	char* concatenated = new char[line1.size() + line2.size() + 1];

	size_t concatIndex = 0, index1 = 0, index2 = 0;
	while (line1[index1] != '\0') {
		concatenated[concatIndex++] = line1[index1++];
	}
	while (line2[index2] != '\0') {
		concatenated[concatIndex++] = line2[index2++];
	}
	concatenated[concatIndex] = '\0';

	Line toReturn = Line(concatenated);
	delete[] concatenated;

	return toReturn;
}