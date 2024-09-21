#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45) {
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
	std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : Aform(other) {
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

void RobotomyRequestForm::robotomizing(Bureaucrat& bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > getGradeToExecute()) {
		throw GradeTooLowException();
	}
	std::srand(time(0));
	int success = std::rand() % 2;

	std::cout << "Bureaucrat: " << bureaucrat.getName() << " executes " << getName() << std::endl;
	if (success) {
		std::cout << "Drilling noises... " << _target << " has been robotomized successfully!" << std::endl;
	} else {
		std::cout << "Drilling noises... " << _target << " robotomy failed." << std::endl;
	}
}

void Form::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}