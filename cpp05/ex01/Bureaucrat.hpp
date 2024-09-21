#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include "Exceptions.hpp"
# include "Form.hpp"


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