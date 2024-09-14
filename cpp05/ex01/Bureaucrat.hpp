#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>
# include "Form.hpp"

class GradeTooHighException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high";
		}
};

class GradeTooLowException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low";
		}
};

class Bureaucrat {
	public:
		Bureaucrat(const std::string name, int grade);
		~Bureaucrat();
		Bureaucrat(Bureaucrat &other);
		Bureaucrat& operator=(Bureaucrat &other);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade() throw(GradeTooHighException);
		void decrementGrade() throw(GradeTooLowException);
		void signForm(Form &form);

	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif