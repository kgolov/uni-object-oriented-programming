#include <iostream>
#include "vector.h"

Vector::Vector() {
	size = 1;
	arr = new int[size];
}

Vector::Vector(size_t _size) {
	size = _size;
	arr = new int[size];
}

int Vector::getElement(size_t _index) {
	if (_index >= index) {
		return 0;
	}

	return arr[_index];
}

bool Vector::isFull() {
	return (index >= size);
}

bool Vector::isEmpty() {
	return (index == 0);
}

void Vector::addElement(int element) {
	Vector::addElementAtIndex(element, index);
}

void Vector::addElementAtIndex(int element, size_t _index) {
	// See if index is over the allowed size
	if (_index > size) {
		return;
	}

	// Determine if we need a new array
	if (isFull()) {
		int* newArr = new int[size * 2];

		// Copy all elements form the old array to the new
		for (size_t i = 0; i < size; i++) {
			newArr[i] = arr[i];
		}

		size *= 2;

		delete[] arr;
		arr = newArr;
		newArr = nullptr;
	}

	// Move all elements after the index to the right
	if (_index != index) {
		for (size_t i = index; i > _index; i--) {
			arr[i] = arr[i - 1];
		}
	}

	// Save the element
	arr[_index] = element;
	// Increment the index counter
	index++;
}

void Vector::removeElement(size_t _index) {
	// Move all elements after the index to the left
	for (size_t i = _index + 1; i <= index; i++) {
		arr[i - 1] = arr[i];
	}
	
	index--;
}

void Vector::print() {
	std::cout << '(';
	
	size_t i;
	for (i = 0; i < index - 1; i++) {
		std::cout << getElement(i) << ", ";
	}
	
	std::cout << getElement(i) << ')';
}