#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Exceptions.hpp"

class Bureaucrat;

class Form {
	public:
		Form(const std::string name, int gradeToSign, int gradeToExecute) throw(GradeTooHighException, GradeTooLowException);
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
