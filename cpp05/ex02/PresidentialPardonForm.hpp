#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{
	private:
		std::string	_target;

	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string const target);
		PresidentialPardonForm(PresidentialPardonForm const& other);
		~PresidentialPardonForm();
		PresidentialPardonForm& operator=(PresidentialPardonForm const& other);

		void informPardon() const;
		void execute(Bureaucrat const& executor) const
		throw(GradeTooLowException, GradeTooHighException, FormIsNotSignedException);
};
 
#endif