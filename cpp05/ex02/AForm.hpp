#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Exceptions.hpp"

class Bureaucrat;

class AForm {
	public:
		AForm(const std::string name, int gradeToSign, int gradeToExecute) throw(GradeTooHighException, GradeTooLowException);
		~AForm();
		AForm(const AForm &other);
		AForm& operator=(const AForm &other);

		std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const;
		bool isSigned() const;
		virtual void beSigned(Bureaucrat &bureaucrat) = 0; //definindo metodo puro;

	private:
		std::string const _name;
		bool _isSigned;
		int const _gradeToSign;
		int const _gradeToExecute;
};

std::ostream& operator<<(std::ostream& os, AForm const& form);

#endif
