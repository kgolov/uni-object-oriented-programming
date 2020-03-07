#include <iostream>
#include "Product.h"
#include "Store.h"

void testProduct() {
	// Test constructors
	Product prod1;
	Product prod2("12345", "Nokian", "Hakkapeliita", "215/65R17", 4, 100.0);
	Product prod3("34567", "Dunlop", "165/70R13", 12, 65.0);

	// Test copy constructor and operator =
	Product prod4(prod2);
	prod1 = prod3;
	std::cout << prod1 << prod2 << prod3 << prod4;
}

void testStore() {
	// Test constructors
	Store st1, st2(Product("34567", "Dunlop", "165/70R13", 12, 65.0));
	Store st3;

	// Test isEmpty
	std::cout << "st1 isEmpty: " << st1.isEmpty() << ", expected 1" << std::endl;
	std::cout << "st2 isEmpty: " << st2.isEmpty() << ", expected 0" << std::endl << std::endl;

	// Test operator=, displayProducts and operator <<, operator +=
	st1 = st2;
	st2 += Product("12345", "Nokian", "Hakkapeliita", "215/65R17", 4, 100.0);
	st1.displayProducts();
	std::cout << st2;

	// Test adding and deleteing products, auto resizing and shrinking
	st2 += Product();
	st2 += Product();
	st2 += Product("345456", "Last", "Test", "200/80R16");
	st2 += Product("12345", "This", "Should", "Not Be Added");

	// Use debugger here to see if shrink works correctly
	st2.deleteAt(2);
	st2.deleteAt(2);

	std::cout << st2;
}

int main() {
	// testProduct();
	// testStore();

	char control;
	Store store;

	std::cout << "Online tyre store: " << store.numberOfProducts() << " currently added products." << std::endl;
	std::cout << "A Add new product\nX Delete product\nC Change product\nD Display products\nQ Quit\n\n";
	std::cout << "Enter character: ";
	std::cin >> control;

	std::cout << std::endl;

	while (control != 'Q') {
		if (control == 'A') {
			std::cout << "*Adding new product." << std::endl;

			Product toAdd;
			char buffer[255];
			int count;
			double price;

			std::cout << "Please enter a unique SKU: ";

			do {
				std::cin >> buffer;

				if (store.uniqueExists(buffer)) {
					std::cout << "Invalid SKU, please enter again: ";
				}
			} while (store.uniqueExists(buffer));

			toAdd.setSKU(buffer);

			std::cout << "Please enter a brand name: ";
			std::cin >> buffer;
			toAdd.setBrand(buffer);

			std::cout << "Please enter a model: ";
			std::cin >> buffer;
			toAdd.setModel(buffer);

			std::cout << "Please enter the size: ";
			std::cin >> buffer;
			toAdd.setSize(buffer);

			std::cout << "Please enter quantity in stock: ";
			std::cin >> count;
			toAdd.setCount(count);

			std::cout << "Please enter price: ";
			std::cin >> price;
			toAdd.setPrice(price);

			store += toAdd;

			std::cout << std::endl << "Product with the following parameters: " << std::endl << toAdd;
			std::cout << "successfully added." << std::endl << std::endl;
		}
		if (control == 'X') {
			std::cout << "*Deleting a product." << std::endl;
			std::cout << "Store contains " << store.numberOfProducts() <<
				" products. " << std::endl << "Enter the number of the product which you want to delete: ";
			int index;
			std::cin >> index;
			std::cout << std::endl;

			if (store.deleteAt(index - 1)) {
				std::cout << "Product number " << index << " deleted successfully." << std::endl << std::endl;
			}
			else {
				std::cout << "Error deleting product number" << index << "!" << std::endl << std::endl;
			}
		}
		if (control == 'C') {
			std::cout << "*Changing a product." << std::endl;
			std::cout << "Store contains " << store.numberOfProducts() <<
				" products. " << std::endl << "Enter the number of the product which you want to change: ";
			int index;
			std::cin >> index;
			std::cout << std::endl;

			if (index < 0 || index > store.numberOfProducts()) {
				std::cout << "Couldn't find such product." << std::endl << std::endl;
			}
			else {
				std::cout << "Changing product: " << std::endl;
				std::cout << index << ". " << store[index - 1] << std::endl;
				std::cout << "N Change SKU\nB Change Brand\nM Change Model\nS Change Size\nC Change Count\n";
				std::cout << "P Change Price\n" << std::endl;

				std::cout << "Enter character: ";
				std::cin >> control;
				std::cout << std::endl;

				if (control == 'N') {
					std::cout << "Enter new SKU: ";

					char buffer[255];

					do {
						std::cin >> buffer;

						if (store.uniqueExists(buffer)) {
							std::cout << "Invalid SKU, please enter again: ";
						}
					} while (store.uniqueExists(buffer));

					store[index - 1].setSKU(buffer);
				}
				if (control == 'B') {
					std::cout << "Enter new Brand: ";

					char buffer[255];
					std::cin >> buffer;
					store[index - 1].setBrand(buffer);
				}
				if (control == 'M') {
					std::cout << "Enter new Model: ";

					char buffer[255];
					std::cin >> buffer;
					store[index - 1].setModel(buffer);
				}
				if (control == 'S') {
					std::cout << "Enter new Size: ";

					char buffer[255];
					std::cin >> buffer;
					store[index - 1].setSize(buffer);
				}
				if (control == 'C') {
					std::cout << "Enter new Count: ";

					int number;
					std::cin >> number;
					store[index - 1].setCount(number);
				}
				if (control == 'P') {
					std::cout << "Enter new Price: ";

					double number;
					std::cin >> number;
					store[index - 1].setPrice(number);
				}
			}
		}
		if (control == 'D') {
			std::cout << "*Displaying products." << std::endl;
			std::cout << store << std::endl;
		}

		std::cout << "Online store: " << store.numberOfProducts() << " currently added products." << std::endl;
		std::cout << "A Add new product\nX Delete product\nC Change product\nD Display products\nQ Quit\n\n";
		std::cout << "Enter character: ";
		std::cin >> control;
		std::cout << std::endl;
	}

	return 0;
}