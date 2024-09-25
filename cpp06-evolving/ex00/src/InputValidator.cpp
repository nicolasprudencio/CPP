#include "InputValidator.hpp"

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


	if (*end == '\0' && value >= std::numeric_limits<int>::min() && value <= std::numeric_limits<int>::max()) {
		return true;
	}
	return false;
}

bool InputValidator::isValidFloat(const std::string& input) {
	if (input == "-inff" || input == "+inff" || input == "nanf") {
		return true;
	}

	char* end;
	std::strtof(input.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0') {
		return true;
	}
	return false;
}

bool InputValidator::isValidDouble(const std::string& input) {
	if (input == "-inf" || input == "+inf" || input == "nan") {
		return true;
	}

	char* end;
	std::strtod(input.c_str(), &end);
	if (*end == '\0') {
		return true;
	}
	return false;
}

void InputValidator::isValidInput(const std::string& input) throw(InvalidInputException){
	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		return;
	}
	if (input.find('.') == std::string::npos) {
		if (!isValidInt(input)) {
			throw InvalidInputException();
		}
	}
	else if (input.find('f') != std::string::npos) {
		if (!isValidFloat(input)) {
			throw InvalidInputException();
		}
	}
	else if (!isValidDouble(input)) {
		throw InvalidInputException();
	}
}

const char* InputValidator::InvalidInputException::what() const throw () {
	return "Error: invalid input";
}