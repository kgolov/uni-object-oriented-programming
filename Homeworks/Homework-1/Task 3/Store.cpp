#include "Store.h"

Store::Store() {
	maxSize = 1;
	products = new Product[maxSize];
	current = 0;
}

Store::~Store() {
	delete[] products;
}

Store::Store(const Product& toAdd) {
	maxSize = 1;
	products = new Product[maxSize];
	current = 0;

	add(toAdd);
}

Store::Store(const Store& toCopy) : maxSize(toCopy.maxSize), current(toCopy.current) {
	products = new Product[maxSize];

	for (int i = 0; i < current; i++) {
		products[i] = toCopy.products[i];
	}
}

Store& Store::operator=(const Store& toCopy) {
	if (this != &toCopy) {
		maxSize = toCopy.maxSize;
		current = toCopy.current;

		delete[] products;
		products = new Product[maxSize];
		for (int i = 0; i < current; i++) {
			products[i] = toCopy.products[i];
		}
	}
	return *this;
}

bool Store::isFull() const {
	return current >= maxSize;
}

bool Store::isEmpty() const {
	return current <= 0;
}

bool Store::needsShrink() const {
	return current < (maxSize / 2);
}

void Store::resize() {
	maxSize *= 2;

	Product* newProducts = new Product[maxSize];
	for (int i = 0; i < current; i++) {
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

void Store::shrink() {
	maxSize /= 2;

	Product* newProducts = new Product[maxSize];
	for (int i = 0; i < current; i++) {
		newProducts[i] = products[i];
	}

	delete[] products;
	products = newProducts;
}

void Store::displayProducts() const {
	std::cout << *this;
}

const int Store::numberOfProducts() const {
	return current;
}

void Store::add(const Product& toAdd) {
	if (uniqueExists(toAdd.getSKU())) {
		// If the SKU already exists in the store, do not add the product
		return;
	}

	if (isFull()) {
		resize();
	}	

	products[current] = toAdd;
	current++;
}

void Store::operator+=(const Product& toAdd) {
	add(toAdd);
}

bool Store::deleteAt(int index) {
	if (index < 0 || index >= current) {
		return false;
	}

	// Move all elements right of the deleted one to the left
	for (int i = index + 1; i < current; i++) {
		products[i - 1] = products[i];
	}

	// Decrement the current elements counter
	current--;

	// Check if we can shrink the array
	if (needsShrink()) {
		shrink();
	}

	return true;
}

bool Store::uniqueExists(const char* _SKU) const {
	if (_SKU == nullptr || strcmp(_SKU, "") == 0) {
		return false;
	}

	for (int i = 0; i < current; i++) {
		if (strcmp(products[i].getSKU(), _SKU) == 0) {
			return true;
		}
	}

	return false;
}

Product& Store::operator[](int index) const {
	if (index < 0 || index >= current) {
		index = 0;
	}

	return products[index];
}

std::ostream& operator<<(std::ostream& os, const Store& obj) {
	if (obj.isEmpty()) {
		os << "No products in store." << std::endl;
		return os;
	}

	os << obj.numberOfProducts() << " products in store:" << std::endl;
	for (int i = 0; i < obj.numberOfProducts(); i++) {
		os << (i + 1) << ". " << obj.products[i];
	}

	os << std::endl;

	return os;
}