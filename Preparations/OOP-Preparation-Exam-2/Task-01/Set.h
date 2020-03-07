#pragma once

template <class T>
class Set {
	int index;
	int maxSize;
	T* elements = nullptr;

	const bool isFull() const;
	void resize();

public:
	Set();
	~Set();
	Set(const Set& toCopy);
	Set& operator=(const Set& toCopy);

	void insert(const T& element);
	void erase(const T& element);
	const bool contains(const T& element) const;
	const int size() const;
	const T& operator[](const int index) const;

	template <class T>
	friend Set<T> Union(const Set<T>& set1, const Set<T>& set2);
	template <class T>
	friend Set<T> Intersection(const Set<T>& set1, const Set<T>& set2);
};