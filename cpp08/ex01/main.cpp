#include "includes/Span.hpp"

// int main(void)
// {
// 	Span sp(11000);
	
// 	try {
// 		for (int i = 0; i < 10000; i++)
// 			sp.addNumber(i);
// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}

// 	return 0;
// }


int main(void)
{
	Span sp(5);
	std::vector<int> v;
	
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	

	try {
		sp.addNumbers(v.begin(), v.end());
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
		std::cout << sp << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}

// int main()
// {
// 	Span sp = Span(5);

// 	try {
// 		sp.addNumber(6);
// 		sp.addNumber(3);
// 		sp.addNumber(17);
// 		sp.addNumber(9);
// 		sp.addNumber(11);
// 		// sp.addNumber(11);

// 		std::cout << sp.shortestSpan() << std::endl;
// 		std::cout << sp.longestSpan() << std::endl;
// 	} catch (std::exception &e) {
// 		std::cout << e.what() << std::endl;
// 	}
// 	return 0;
// }