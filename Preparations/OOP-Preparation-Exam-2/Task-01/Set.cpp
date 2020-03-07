#include "Set.h"

template <class T>
Set<T>::Set() {
	index = 0;
	maxSize = 1;
	elements = new T[maxSize];
}

template <class T>
Set<T>::~Set() {
	delete[] elements;
}

template <class T>
Set<T>::Set(const Set<T>& toCopy) {
	index = toCopy.index;
	maxSize = toCopy.maxSize;
	elements = new T[maxSize];

	for (int i = 0; i < index; i++) {
		elements[i] == toCopy.elements[i];
	}
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& toCopy) {
	delete[] elements;

	index = toCopy.index;
	maxSize = toCopy.maxSize;
	elements = new T[maxSize];

	for (int i = 0; i < index; i++) {
		elements[i] == toCopy.elements[i];
	}
}

template <class T>
const bool Set<T>::isFull() const {
	return index >= maxSize;
}

template <class T>
void Set<T>::resize() {
	maxSize *= 2;

	T* newElements = new T[maxSize];

	for (int i = 0; i < index; i++) {
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
}

template <class T>
void Set<T>::insert(const T& element) {
	if (!contains(element)) {
		if (isFull()) {
			resize();
		}

		elements[index++] = element;
	}
}

template <class T>
void Set<T>::erase(const T& element) {
	int found = -1;

	for (int i = 0; i < index; i++) {
		if (elements[i] == element) {
			// Element is found, delete at this index
			found = i;
		}
	}

	if (found != -1) {
		for (int i = found; i < index - 1; i++) {
			// Move all elements right of the found element one position to the left
			elements[i] = elements[i + 1];
		}
	}
}

template <class T>
const bool Set<T>::contains(const T& element) const {
	bool isFound = false;

	for (int i = 0; i < index; i++) {
		if (elements[i] == element) {
			isFound = true;
		}
	}

	return isFound;
}

template <class T>
const int Set<T>::size() const {
	return index;
}

template <class T>
const T& Set<T>::operator[](const int index) const {
	if (index < 0 || index >= this->index) {
		return T();
	}

	return elements[index];
}

template <class T>
Set<T> Union(const Set<T>& set1, const Set<T>& set2) {
	Set<T> result;

	for (int i = 0; i < set1.index; i++) {
		result.insert(set1.elements[i]);
	}

	for (int i = 0; i < set2.index; i++) {
		result.insert(set2.elements[i]);
	}

	return result;
}

template <class T>
Set<T> Intersection(const Set<T>& set1, const Set<T>& set2) {
	Set<T> result;

	if (set1.index < set2.index) {
		// First set is smaller than the second
		for (int i = 0; i < set1.index; i++) {
			if (set2.contains(set1.elements[i])) {
				// Element is in both sets
				result.insert(set1.elements[i]);
			}
		}
	}
	else {
		// Second set is bigger than or same as first one
		for (int i = 0; i < set2.index; i++) {
			if (set1.contains(set2.elements[i])) {
				// Element is in both sets
				result.insert(set2.elements[i]);
			}
		}
	}
}