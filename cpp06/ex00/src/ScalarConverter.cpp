#include "../include/ScalarConverter.hpp"
#include "../include/InputValidator.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &obj) {
	(void) obj;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &obj) {
	(void) obj;
	return (*this);
}

ScalarConverter::~ScalarConverter() {}

void	charConversor(const std::string &str) {
	std::istringstream iss(str);
	int c;

	if (str.size() == 1 && !std::isdigit(str[0]) && std::isprint(str[0])) {
		std::cout << "char: " << static_cast<char>(str[0]) << std::endl;
		return ;
	}
	else if(str.size() > 1 && iss >> c && c <= 127 && c >= 0 && std::isprint(c)) {
		std::cout << "char: " << static_cast<char>(c) << std::endl;
		return ;
	}
	std::cout << "char: impossible to display!" << std::endl;
}

void		intConversor(std::string &str) {
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
			std::cout << "int: " << static_cast<int>(i) << std::endl;
			return;
		}
	}
	std::cout << "int: impossible to display!" << std::endl;
}

static bool checkFloat(const float f) {
	if ((f == std::floor(f) || f == std::ceil(f)) &&
		std::abs(f - round(f)) < 0.001)
		return true;
	return false;
}

static bool checkDouble(const double d) {
	if ((d == std::floor(d) || d == std::ceil(d)) &&
		std::abs(d - round(d)) < 0.001)
		return true;
	return false;
}

void floatConversor(std::string &str) {
	if (InputValidator::isValidFloat(str)) {
		float value = static_cast<float>(atof(str.c_str()));
		if (str.find('.') == std::string::npos || checkFloat(value))
		{
			if (str.size() == 1 && !std::isdigit(str[0]))
				value = static_cast<int>(str[0]);
			std::cout << "float: " << value << ".0f" << std::endl;
		}
		else
			std::cout << "float: " << value << "f" << std::endl;
		return;
	}
	std::cout << "float: impossible to display!" << std::endl;
}

void	doubleConversor(std::string &str) {
	if (InputValidator::isValidDouble(str))
	{
		double value = static_cast<double>(atof(str.c_str()));
		if (str.find('.') == std::string::npos || checkDouble(value))
		{
			if (str.size() == 1 && !std::isdigit(str[0]))
				value = static_cast<int>(str[0]);
			std::cout << "double: " << value << ".0" << std::endl;
		}
		else
			std::cout << "double: "<< value << std::endl;
		return;
	}
	std::cout << "double: impossible to display!" << std::endl;
}

void	ScalarConverter::convert(std::string &str) {
	charConversor(str);
	intConversor(str);
	floatConversor(str);
	doubleConversor(str);
}