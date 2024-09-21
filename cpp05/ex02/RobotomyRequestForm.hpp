#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include "AForm.hpp"
# include "Exceptions.hpp"

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

		void robotomizing(Bureaucrat& bureaucrat) throw(GradeTooLowException);
};
 
#endif