#ifndef __STORE_H
#define __STORE_H

#include "Product.h"

class Store {
	Product* products = nullptr;
	int current;
	int maxSize;

	bool isFull() const;
	bool needsShrink() const;
	void resize();
	void shrink();

public:
	Store();
	~Store();
	Store(const Product& toAdd);
	Store(const Store& toCopy);
	Store& operator=(const Store& toCopy);

	// Getters
	bool isEmpty() const;
	void displayProducts() const;
	const int numberOfProducts() const;

	// Setters
	void add(const Product& toAdd);
	void operator+=(const Product& toAdd);
	bool deleteAt(int index);

	// Other methods and operators
	bool uniqueExists(const char* _SKU) const;
	Product& operator[](int index) const;
	friend std::ostream& operator<<(std::ostream& os, const Store& obj);
};

#endif