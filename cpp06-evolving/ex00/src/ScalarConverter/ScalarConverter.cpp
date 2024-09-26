#include "ScalarConverter.hpp"
#include "../InputValidator.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	(void) obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
	(void) obj;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	char_conversor(const std::string &str) {
	std::istringstream iss(str);
	int c;

	if (str.size() == 1 && !std::isdigit(str[0])) {
		std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
		return ;
	}
	else if(str.size() > 1 && iss >> c && c <= 127 && c >= 0) {
		std::cout << "char: " << static_cast<char>(c) << std::endl;
		return ;
	}
	std::cout << "char: impossible to display!" << std::endl;
}

void		int_conversor(std::string &str) {
	std::istringstream iss(str);
	int i;

	if (InputValidator::isValidInt(str))
	{
		if (str.size() == 1 && !std::isdigit(str[0])) {
			std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
			return;
		}
		else if (iss >> i)
		{
			std::cout << "int: " << i << std::endl;
			return;
		}
	}
	std::cout << "int: impossible to display!" << std::endl;
}

void	float_conversor(std::string &str) {
	if (InputValidator::isValidFloat(str))
	{
		std::cout << "float: " << atof(str.c_str()) << "f" << std::endl;
		return;
	}
	std::cout << "float: impossible to display!" << std::endl;
}

void	double_conversor(std::string &str) {
	if (InputValidator::isValidFloat(str))
	{
		std::cout << "double: "<< atof(str.c_str()) << std::endl;
		return;
	}
	std::cout << "double: impossible to display!" << std::endl;
}

void	ScalarConverter::convert(std::string &str) {
	char_conversor(str);
	int_conversor(str);
	float_conversor(str);
	double_conversor(str);
}