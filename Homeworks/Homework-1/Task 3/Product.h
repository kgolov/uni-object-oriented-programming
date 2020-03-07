#ifndef __PRODUCT_H
#define __PRODUCT_H

#include <iostream>

// We will be working with automobile tyres.
class Product {
	// Unique Stock Keeping Unit
	char* SKU = nullptr;
	// Manufacturer name
	char* brand = nullptr;
	// Exact model of the tyre
	char* model = nullptr;
	// Size of the tyre (e.g. 165/70R13)
	char* size = nullptr;
	// Number of products in stock
	int count;
	// Price for one
	double price;

	// Declare Store class as friend
	friend class Store;

public:
	Product();
	~Product();
	Product(const char* _SKU, const char* _brand, const char* _model, const char* _size, 
		const int _count = 0, const double _price = 0);
	Product(const char* _SKU, const char* _brand, const char* _size, const int _count = 0, const double _price = 0);
	Product(const Product& toCopy);
	Product& operator=(const Product& toCopy);

	// Getters
	const char* getSKU() const;
	const char* getBrand() const;
	const char* getModel() const;
	const char* getSize() const;
	const int getCount() const;
	const double getPrice() const;

	// Setters
	void setSKU(const char* _SKU);
	void setBrand(const char* _brand);
	void setModel(const char* _model);
	void setSize(const char* _size);
	void setCount(const int _count);
	void setPrice(const double _price);

	// Other methods and operators
	friend std::ostream& operator<<(std::ostream& os, const Product& obj);
};

#endif