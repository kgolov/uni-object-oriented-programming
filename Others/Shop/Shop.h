#ifndef __SHOP_H
#define __SHOP_H

class Shop {
	int products;
	int inStock;
	int* stockByType;

public:
	Shop();
	Shop(int products);
	Shop(int products, int inStock);
	Shop(int products, int inStock, int* listOfProducts);

	~Shop();


};

#endif