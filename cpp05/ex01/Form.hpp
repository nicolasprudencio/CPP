#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class GradeTooHighToSignException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too high and it's impossible to sign the form";
		}
};

class GradeTooLowToSignException: public std::exception {
	public:
		virtual const char* what() const throw() {
			return "Grade is too low and it's impossible to sign the form";
		}
};

class Form {
	public:
		Form(const std::string name, int gradeToSign, int gradeToExecute);
		~Form();
		Form(const Form &other);
		Form& operator=(const Form &other);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		bool isSigned() const;
		void beSigned(Bureaucrat &bureaucrat);

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif
