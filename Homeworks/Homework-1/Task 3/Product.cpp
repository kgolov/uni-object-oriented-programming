#include "Product.h"

Product::Product() : count(0), price(0) {
	setSKU("");
	setBrand("");
	setModel("");
	setSize("");
}

Product::~Product() {
	delete[] SKU;
	delete[] brand;
	delete[] model;
	delete[] size;
}

Product::Product(const char* _SKU, const char* _brand, const char* _model, const char* _size,
	const int _count, const double _price) {
	setSKU(_SKU);
	setBrand(_brand);
	setModel(_model);
	setSize(_size);
	setCount(_count);
	setPrice(_price);
}

Product::Product(const char* _SKU, const char* _brand, const char* _size, 
	const int _count, const double _price) {
	setSKU(_SKU);
	setBrand(_brand);
	setModel("");
	setSize(_size);
	setCount(_count);
	setPrice(_price);
}

Product::Product(const Product& toCopy) : count(toCopy.getCount()), price(toCopy.getPrice()) {
	setSKU(toCopy.getSKU());
	setBrand(toCopy.getBrand());
	setModel(toCopy.getModel());
	setSize(toCopy.getSize());
}

Product& Product::operator=(const Product& toCopy) {
	if (this != &toCopy) {
		setSKU(toCopy.getSKU());
		setBrand(toCopy.getBrand());
		setModel(toCopy.getModel());
		setSize(toCopy.getSize());
		setCount(toCopy.getCount());
		setPrice(toCopy.getPrice());
	}
	return *this;
}

const char* Product::getSKU() const {
	return SKU;
}

const char* Product::getBrand() const {
	return brand;
}

const char* Product::getModel() const {
	return model;
}

const char* Product::getSize() const {
	return size;
}

const int Product::getCount() const {
	return count;
}

const double Product::getPrice() const {
	return price;
}

void Product::setSKU(const char* _SKU) {
	delete[] SKU;

	if (_SKU == nullptr) {
		SKU = new char[1];
		SKU[0] = '\0';
	}
	else {
		int len = strlen(_SKU) + 1;
		SKU = new char[len];
		strcpy_s(SKU, len, _SKU);
	}
}

void Product::setBrand(const char* _brand) {
	delete[] brand;

	if (_brand == nullptr) {
		brand = new char[1];
		brand[0] = '\0';
	}
	else {
		int len = strlen(_brand) + 1;
		brand = new char[len];
		strcpy_s(brand, len, _brand);
	}
}

void Product::setModel(const char* _model) {
	delete[] model;

	if (_model == nullptr) {
		model = new char[1];
		model[0] = '\0';
	}
	else {
		int len = strlen(_model) + 1;
		model = new char[len];
		strcpy_s(model, len, _model);
	}
}

void Product::setSize(const char* _size) {
	delete[] size;

	if (_size == nullptr) {
		size = new char[1];
		size[0] = '\0';
	}
	else {
		int len = strlen(_size) + 1;
		size = new char[len];
		strcpy_s(size, len, _size);
	}
}

void Product::setCount(const int _count) {
	if (_count < 0) {
		return;
	}

	count = _count;
}

void Product::setPrice(const double _price) {
	if (_price < 0) {
		return;
	}

	price = _price;
}

std::ostream& operator<<(std::ostream& os, const Product& obj) {
	os << "SKU:" << obj.getSKU() << '\t' << obj.getBrand() << " " << obj.getModel() << " " <<
		obj.getSize() << ",\t " << obj.getCount() << " in stock, Price: " << obj.getPrice() << std::endl;

	return os;
}