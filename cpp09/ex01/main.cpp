#include <iostream>
#include "./includes/RPN.hpp"



int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./rpn [input file]" << std::endl;
		return 1;
	}
	try {
		RPN::validateInputArgument(argv[1]);
		std::cout << RPN::calculate(argv[1]) << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}