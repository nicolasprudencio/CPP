#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cmath>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other) {
	*this = other;
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

void RobotomyRequestForm::robotomizing() const {
	
	srand(time(NULL));
	int success = rand() % 2;
	if (success == 0) {
		std::cout << "Drilling noises... " << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Drilling noises... " << _target << " robotomy failed." << std::endl;
	}
}

void RobotomyRequestForm::execute(Bureaucrat const& executor) const 
throw (GradeTooLowException, GradeTooHighException, FormIsNotSignedException){
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSignedException();
	robotomizing();
}
