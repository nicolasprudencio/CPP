#include "ScalarConverter/ScalarConverter.hpp"
#include "InputValidator.hpp"

void	printNan();
void	printPlusInf();
void	printLessInf();
void	printDefaultErr();

int main(int ac, char **av) {
	std::string err[6] = {"nan", "+inf", "-inf", "nanf", "+inff", "-inff"};
	void (*functions[])(void) = {
		&printNan,
		&printPlusInf,
		&printLessInf
	};


	if (ac != 2) {
		std::cerr << "Error: invalid num arguments" << std::endl;
		return (1);
	}
	try {
		InputValidator::isValidInput(av[1]);
		std::string input(av[1]);
		// ScalarConverter::convert(input);
	} catch (const std::exception &e) {
		for (int i = 0; i < 6; i++) {
			if (av[1] == err[i]) {
				functions[i % 3]();
				return (1);
			}
		}
		printDefaultErr();
		return (1);
	}
}

void printNan() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}

void printPlusInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: +inff" << std::endl;
	std::cout << "double: +inf" << std::endl;
}

void printLessInf() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: -inff" << std::endl;
	std::cout << "double: -inf" << std::endl;
}

void printDefaultErr() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}
