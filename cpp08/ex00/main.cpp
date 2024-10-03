#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>
#include "easyfind.hpp"

int main() {
	std::vector<int> vec;


	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);

	try {
	
		std::vector<int>::iterator it = easyfind(vec, 30);
		std::cout << "Found: " << *it << std::endl;

	
		it = easyfind(vec, 50);
		std::cout << "Found: " << *it << std::endl;
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
