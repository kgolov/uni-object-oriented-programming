#ifndef __LINE_H
#define __LINE_H

class Line {
	char* text;
	size_t length;

public:
	Line();
	~Line();
	Line(const char* str);
	Line(const Line& toCopy);

	Line& operator=(const Line& toCopy);
	
	const char operator[](int index) const;

	// Getters
	const char* value() const;
	const size_t size() const;

	// Setters
	void setValue(const char* str);
};

Line SplitLine(Line& toSplit, size_t index);
Line ConcatenateLines(const Line& line1, const Line& line2);

#endif 