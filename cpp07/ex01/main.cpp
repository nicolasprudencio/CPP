#include <iostream>
#include "iter.hpp"

int	main(void) {
	int array[] = {1, 2, 3, 4, 5};

	for (int i = 0; i < 5; i++) {
			std::cout << array[i] << std::endl;
	}

	iter(array, 5, increment);
	std::cout << "After increment:" << std::endl;

	for (int i = 0; i < 5; i++) {
		std::cout << array[i] << std::endl;
	}

	std::string string_arr[] = {"Hello", "World", "!"};

	std::cout << "Executing print template function:" << std::endl;

	iter(string_arr, 3, print);

	return 0;
}
