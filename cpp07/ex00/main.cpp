#include <iostream>
#include "whatever.hpp"

int	main(void) {
	int x = 2;
	int y = 4;
	char a = 'a';
	char A = 'A';

	std::cout << "x: " << x << " y: " << y << std::endl;
	std::cout << "a: " << a << " A: " << A << std::endl;

	std::cout << "max(x, y): " << ::max(x, y) << std::endl;
	std::cout << "min(x, y): " << ::min(x, y) << std::endl;
	std::cout << "max(a, A): " << ::max(a, A) << std::endl;
	std::cout << "min(a, A): " << ::min(a, A) << std::endl;

	std::cout << "x, y after swap values: " << std::endl;
	::swap(x, y);
	std::cout << "x: " << x << " y: " << y << std::endl;

	return 0;
}

// int main( void ) {
// 	int a = 2;
// 	int b = 3;

// 	::swap( a, b );
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
// 	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
// 	std::string c = "chaine1";
// 	std::string d = "chaine2";
// 	::swap(c, d);
// 	std::cout << "c = " << c << ", d = " << d << std::endl;
// 	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
// 	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
// 	return 0;
// }