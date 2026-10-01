#include <iostream>
#include <vector>
#include "vector.h"
int main() {
	std::vector<int> vec(7);
	int val = 1;

	for (auto it = vec.begin(); it != vec.end(); it++) {
		*it = val++;
	}

	for (auto it = vec.begin(); it != vec.end(); it++) {
		std::cout << *it << " ";
	}

	std::cout << std::endl;

	Vector<int> my_vec(7);
	val = 1;

	for (int i = 0; i < 7; i++) {
		my_vec[i] = val++;
	}

	for (int i = 0; i < 7; i++) {
		std::cout << my_vec[i] << " ";
	}

	std::cout << std::endl;

	val = 1;

	for (auto it = my_vec.begin(); it != my_vec.end(); it++) {
		*it = val++;
	}

	for (auto it = my_vec.begin(); it != my_vec.end(); it++) {
		std::cout << *it << " ";
	}
	return 0;
}