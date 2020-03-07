#include <iostream>
#include "Line.h"

void testLine() {
	// Test constructors
	Line line1, line2("Hello");

	// Test getters
	std::cout << "Line1 is: " << line1.value() << ", length is: " << line1.size() << ";" << std::endl;
	std::cout << "// Expected empty string, length 0" << std::endl;
	std::cout << "Line2 is: " << line2.value() << ", length is: " << line2.size() << ";" << std::endl;
	std::cout << "// Expected \"Hello\", length 5" << std::endl;

	// Test setter
	line1.setValue("This is a test with \n new line");
	std::cout << "Line1 is: " << line1.value() << ", length is: " << line1.size() << ";" << std::endl;
	std::cout << "// Expected \"This is a test with \", length 20" << std::endl;

	// Test copy constructor and operator =
	line1 = line2;
	Line line3(line2);
	line2.setValue("Test");

	std::cout << "Line1 is: " << line1.value() << ", length is: " << line1.size() << ";" << std::endl;
	std::cout << "// Expected \"Hello\", length 5" << std::endl;
	std::cout << "Line2 is: " << line2.value() << ", length is: " << line2.size() << ";" << std::endl;
	std::cout << "// Expected \"Test\", length 4" << std::endl;
	std::cout << "Line3 is: " << line3.value() << ", length is: " << line3.size() << ";" << std::endl;
	std::cout << "// Expected \"Hello\", length 5" << std::endl;
}

void testSplitLine() {
	Line a("Hello, World!");
	Line b = SplitLine(a, 5);
	// a = "Hello", b = ", World!"

	std::cout << "a = \"" << a.value() << "\", b = \"" << b.value() << "\"" << std::endl;
	std::cout << "// Expected  a = \"Hello\", b = \", World!\"" << std::endl;
}

void testConcatenateLines() {
	Line a("Hello");
	Line b(", World!");
	Line c = ConcatenateLines(a, b);
	// c = "Hello, World!"

	std::cout << "c = \"" << c.value() << "\"" << std::endl;
	std::cout << "// Expected c = \"Hello, World!\"" << std::endl;
}

void testText() {
	// TODO!
}

int main() {
	// testLine();
	// testSplitLine();
	// testConcatenateLines();
	// TODO: testText();

	return 0;
}