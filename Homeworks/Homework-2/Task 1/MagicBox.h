#ifndef __MAGICBOX_H
#define __MAGICBOX_H

#include <iostream>
#include <stdlib.h> // For rand and srand functions
#include <time.h>   // For time function

template <class T>
class MagicBox {
	T* elements = nullptr;
	int size;
	int top;

	bool isFull() const;
	bool needsShrinking() const;
	void resize();
	void shrink();
	const int getRandomIndex() const;

public:
	MagicBox();
	~MagicBox();
	MagicBox(const T& toAdd);
	MagicBox(const MagicBox& toCopy);
	MagicBox& operator=(const MagicBox& toCopy);

	// Getters
	bool isEmpty() const;
	void list() const;

	// Setters
	void insert(const T& element);
	void operator+=(const T& element);
	const T pop();
};

template <class T>
MagicBox<T>::MagicBox() {
	size = 1;
	top = 0;
	elements = new T[size];
}

template <class T>
MagicBox<T>::~MagicBox() {
	delete[] elements;
}

template <class T>
MagicBox<T>::MagicBox(const T& toAdd) {
	size = 1;
	top = 0;
	elements = new T[size];

	insert(toAdd);
}

template <class T>
MagicBox<T>::MagicBox(const MagicBox<T>& toCopy) {
	size = toCopy.size;
	top = toCopy.top;
	elements = new T[size];

	for (int i = 0; i < top; i++) {
		elements[i] = toCopy.elements[i];
	}
}

template <class T>
MagicBox<T>& MagicBox<T>::operator=(const MagicBox<T>& toCopy) {
	if (this != &toCopy) {
		size = toCopy.size;
		top = toCopy.top;

		delete[] elements;
		elements = new T[size];

		for (int i = 0; i < top; i++) {
			elements[i] = toCopy.elements[i];
		}
	}
	return *this;
}

template <class T>
bool MagicBox<T>::isFull() const {
	return top >= size;
}

template <class T>
bool MagicBox<T>::needsShrinking() const {
	return top < (size / 2);
}

template <class T>
bool MagicBox<T>::isEmpty() const {
	return top <= 0;
}

template <class T>
void MagicBox<T>::resize() {
	size *= 2;

	T* newElements = new T[size];

	for (int i = 0; i < top; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

template <class T>
void MagicBox<T>::shrink() {
	size /= 2;

	T* newElements = new T[size];

	for (int i = 0; i < top; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

template <class T>
void MagicBox<T>::list() const {
	if (isEmpty()) {
		std::cout << "The box is empty!" << std::endl;
	}
	else {
		std::cout << "The box contains: " << std::endl;
		for (int i = 0; i < top; i++) {
			std::cout << elements[i] << std::endl;
		}
		std::cout << "----------" << std::endl;
	}
}

template <class T>
void MagicBox<T>::insert(const T& element) {
	if (isFull()) {
		resize();
	}
	elements[top++] = element;
}

template <class T>
void MagicBox<T>::operator+=(const T& element) {
	insert(element);
}

template <class T>
const T MagicBox<T>::pop() {
	if (isEmpty()) {
		std::cout << "The box is empty!" << std::endl;
		return T();
	}

	// Select a random index
	int random = getRandomIndex();

	// Save the element at this index
	T element = elements[random];

	// Move all elements right of it
	for (int i = random; i < top - 1; i++) {
		elements[i] = elements[i + 1];
	}
	top--;

	// Return the popped element
	return element;
}

template <class T>
const int MagicBox<T>::getRandomIndex() const {
	srand(time(NULL));
	return rand() % top;
}

#endif