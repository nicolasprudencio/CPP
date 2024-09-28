#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),  _target("default") {
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target) : AForm("PresidentialPardonForm", 25, 5), _target(target) {
	std::cout << "PresidentialPardonForm constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other) {
	*this = other;
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm() {
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

void PresidentialPardonForm::informPardon() const{
	std::cout << _target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const& executor) const
throw (GradeTooLowException, GradeTooHighException, FormIsNotSignedException){
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSignedException();
	informPardon();
}
