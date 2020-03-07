#ifndef __VECTOR_H
#define __VECTOR_H

class Vector {
private:
	int* arr;
	size_t size;
	size_t index = 0;

public:
	// Constructors
	Vector();
	Vector(size_t _size);

	// Getters
	int* getVector() { return arr;   }
	int  getSize()   { return size;  }
	int  getIndex()  { return index; }
	int  getElement(size_t _index);

	bool isFull();
	bool isEmpty();

	// Setters
	void addElement(int element);
	void addElementAtIndex(int element, size_t _index);
	void removeElement(size_t _index);

	// Other operations
	void print();
};

#endif