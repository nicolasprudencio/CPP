#include "Exceptions.hpp"

const char* GradeTooHighException::what() const throw() {
	return "Grade is too high";
}

const char* GradeTooLowException::what() const throw() {
	return "Grade is too low";
}