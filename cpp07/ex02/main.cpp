#include <iostream>
#include <string>
#include "Array.hpp"

int	main(void) {
	Array<int> a(5);
	Array<int> b;
	Array<std::string> c(3);

	a[2] = 3;
	c[0] = "O tal";
	c[1] = "do";
	c[2] = "chupacu";

	const Array<int> d(a);


	std::cout << a[2] << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << c << std::endl;

	// d[2] = 1;

	std::cout << d[2] << std::endl;
	std::cout << d << std::endl;

	try {
		a[6] = 1;
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}