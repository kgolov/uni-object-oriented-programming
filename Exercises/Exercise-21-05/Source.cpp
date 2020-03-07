#include <iostream>
#include "Set.hpp"

int main() {
	Set<int> s1;
	s1.insert(1);
	s1.insert(2);
	s1.insert(6);
	s1.insert(2);
	s1.insert(2);
	s1.insert(5);
	s1.insert(7);

	std::cout << s1 << std::endl;

	Set<int> s2;
	s2.insert(1);
	s2.insert(3);

	std::cout << s2 << std::endl;

	Set<int> s3 = Union(s1, s2);
	Set<int> s4 = Intersection(s1, s2);

	std::cout << s3 << std::endl << s4 << std::endl;


	return 0;
}