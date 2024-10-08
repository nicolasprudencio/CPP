#include "../include/InputValidator.hpp"

bool isNumber(const std::string &str);

InputValidator::InputValidator() {
	std::cout << "InputValidator constructor called" << std::endl;
}

InputValidator::InputValidator(const InputValidator &other) {
	*this = other;
	std::cout << "InputValidator copy constructor called" << std::endl;
}

InputValidator &InputValidator::operator=(const InputValidator &other) {
	(void)other;
	std::cout << "InputValidator overloadoperator called" << std::endl;
	return *this;
}

InputValidator::~InputValidator() {
	std::cout << "InputValidator destructor called" << std::endl;
}

bool InputValidator::isValidChar(const std::string& input) {
	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		return true;
	}
	return false;
}

bool InputValidator::isValidInt(const std::string& input) {
	char* end;
	long value = std::strtol(input.c_str(), &end, 10);

	if (value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) 
		return true;
	return false;
}

bool InputValidator::isValidFloat(const std::string& input) {
	char* end;
	std::strtof(input.c_str(), &end);
	if (*end == 'f' || input.size() == 1 || isNumber(input)) {
		return true;
	}
	return false;
}

bool InputValidator::isValidDouble(const std::string& input) {
	char* end;

	std::strtod(input.c_str(), &end);
	if (*end == '\0' || *end == 'f' || input.size() == 1) {
		return true;
	}
	return false;
}

const char* InputValidator::InvalidInputException::what() const throw () {
	return "Error: invalid input";
}

bool isNumber(const std::string &str) {
	if (str.empty()) {
		return false;
	}

	std::size_t start = (str[0] == '-' || str[0] == '+') ? 1 : 0;

	for (std::size_t i = start; i < str.length(); ++i) {
		if (!std::isdigit(str[i])) {
			return false;
		}
	}

	return true;
}