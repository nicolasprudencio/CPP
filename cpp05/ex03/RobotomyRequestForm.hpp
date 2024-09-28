#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{
	private:
		std::string	_target;

	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const target);
		RobotomyRequestForm(RobotomyRequestForm const& other);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=(RobotomyRequestForm const& other);

		void robotomizing() const;
		void execute(Bureaucrat const& executor) const
		throw (GradeTooLowException, GradeTooHighException, FormIsNotSignedException);
};
 
#endif