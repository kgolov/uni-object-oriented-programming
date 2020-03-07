#ifndef __SET_HPP
#define __SET_HPP

#include <iostream>

template <class T>
class Set {
	T* arr = nullptr;
	int top;
	int maxSize;

	void resize();
	bool isFull() const;

public:
	Set();
	~Set();
	Set(const Set<T>& toCopy);
	Set<T>& operator=(const Set<T>& toCopy);

	bool isEmpty() const;
	void insert(const T& element);
	void erase(const T& element);
	bool contains(const T& element) const;
	const int size() const;
	const T& operator[](const int index) const;

	template <class T>
	friend std::ostream& operator<<(std::ostream& os, const Set<T>& obj);

	template <class T>
	friend Set<T> Union(const Set<T>& first, const Set<T>& second);
	template <class T>
	friend Set<T> Intersection(const Set<T>& first, const Set<T>& second);
};

template <class T>
Set<T>::Set() {
	top = 0;
	maxSize = 1;
	arr = new T[maxSize];
}

template <class T>
Set<T>::~Set() {
	delete[] arr;
}

template <class T>
Set<T>::Set(const Set<T>& toCopy) {
	top = toCopy.top;
	maxSize = toCopy.maxSize;
	arr = new T[maxSize];

	for (int i = 0; i < top; i++) {
		arr[i] = toCopy.arr[i];
	}
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& toCopy) {
	if (this != &toCopy) {
		top = toCopy.top;
		maxSize = toCopy.maxSize;
		arr = new T[maxSize];

		for (int i = 0; i < top; i++) {
			arr[i] = toCopy.arr[i];
		}
	}
	return *this;
}

template <class T>
bool Set<T>::isFull() const {
	return top >= maxSize;
}

template <class T>
bool Set<T>::isEmpty() const {
	return top <= 0;
}

template <class T>
void Set<T>::resize() {
	maxSize *= 2;
	T* newArr = new T[maxSize];

	for (int i = 0; i < top; i++) {
		newArr[i] = arr[i];
	}

	delete[] arr;
	arr = newArr;
}

template <class T>
void Set<T>::insert(const T& element) {
	if (!contains(element)) {
		if (isFull()) {
			resize();
		}

		arr[top++] = element;
	}
}

template <class T>
void Set<T>::erase(const T& element) {
	if (isEmpty() || !contains(element)) {
		return;
	}

	// Else, find element
	int i;
	for (i = 0; i < top; i++) {
		if (arr[i] == element) {
			break;
		}
	}

	// Delete element, i.e move all elements from the right to the left
	for (int j = i + 1; j < top; j++) {
		arr[j - 1] = arr[j];
	}

	// Decrement top counter
	top--;
}

template <class T>
bool Set<T>::contains(const T& element) const {
	bool flag = false;

	for (int i = 0; i < top; i++) {
		if (arr[i] == element) {
			flag = true;
		}
	}

	return flag;
}

template <class T>
const int Set<T>::size() const {
	return top;
}

template <class T>
const T& Set<T>::operator[](const int index) const {
	if (index < 0 || index >= top) {
		return T();
	}

	return arr[index];
}

template <class T>
std::ostream& operator<<(std::ostream& os, const Set<T>& obj) {
	for (int i = 0; i < obj.size(); i++) {
		os << obj[i] << " ";
	}

	os << std::endl;

	return os;
}

template <class T>
Set<T> Union(const Set<T>& first, const Set<T>& second) {
	Set<T>* result = new Set<T>;

	for (int i = 0; i < first.size(); i++) {
		result->insert(first[i]);
	}
	for (int i = 0; i < second.size(); i++) {
		result->insert(second[i]);
	}

	return *result;
}

template <class T>
Set<T> Intersection(const Set<T>& first, const Set<T>& second) {
	Set<T>* result = new Set<T>;

	if (first.size() <= second.size()) {
		for (int i = 0; i < first.size(); i++) {
			if (second.contains(first[i])) {
				result->insert(first[i]);
			}
		}
	}
	else {
		for (int i = 0; i < second.size(); i++) {
			if (first.contains(second[i])) {
				result->insert(second[i]);
			}
		}
	}

	return *result;
}

#endif