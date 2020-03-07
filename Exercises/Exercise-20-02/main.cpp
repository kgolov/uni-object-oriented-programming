#include <iostream>

int main() {
	int* arr = new int[100000000];
	
	int x;
	std::cin >> x;

	delete[] arr;
	return 0;
}