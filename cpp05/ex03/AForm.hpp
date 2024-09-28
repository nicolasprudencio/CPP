#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm {
	public:
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class FormIsNotSignedException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		AForm();
		AForm(const std::string name, int gradeToSign, int gradeToExecute) throw(GradeTooHighException, GradeTooLowException);
		virtual ~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		void beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);
		virtual void execute(Bureaucrat const& executor) const = 0; //definindo metodo puro;

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
