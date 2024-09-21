#ifndef EXCEPTIONS_HPP
# define EXCEPTIONS_HPP

#include <stdexcept>

class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw();
};

class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw();
};


#endif