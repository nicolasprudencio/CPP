#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <stdexcept>

class Bureaucrat {

	public:
		class GradeTooHighException: public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(Bureaucrat &other);
		~Bureaucrat();
		Bureaucrat& operator=(Bureaucrat &other);

		std::string getName() const;
		int getGrade() const;
		void incrementGrade() throw(GradeTooHighException);
		void decrementGrade() throw(GradeTooLowException);

	private:
		std::string const _name;
		int _grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat);

#endif