#ifndef INPUTVALIDATOR_HPP
# define INPUTVALIDATOR_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cctype>
#include <cstdlib>
#include <stdexcept>

class InputValidator
{
	public:
		class InvalidInputException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		InputValidator();
		InputValidator(const InputValidator &other);
		InputValidator &operator=(const InputValidator &other);
		~InputValidator();

	static bool isValidChar(const std::string& input);
	static bool isValidInt(const std::string& input);
	static bool isValidFloat(const std::string& input);
	static bool isValidDouble(const std::string& input);
	static void isValidInput(const std::string& input) throw(InvalidInputException);

};

#endif