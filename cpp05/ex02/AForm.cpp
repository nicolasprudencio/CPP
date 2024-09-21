#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string name, int gradeToSign, int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		std::cout << "Error at form create: " << std::endl;
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		std::cout << "Error at form create: " << std::endl;
		throw GradeTooLowException();
	}
	std::cout << "Form " << _name << " created." << std::endl;
}

AForm::~AForm() {
	std::cout << _name << " destroyed." << std::endl;
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned),_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {
	std::cout << "Form Copy constructor called" << std::endl;
}

AForm& AForm::operator=(const AForm &other) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &other) {
	
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string AForm::getName() const {
	return _name;
}

int AForm::getGradeToSign() const {
	return _gradeToSign;
}

int AForm::getGradeToExecute() const {
	return _gradeToExecute;
}

void AForm::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool AForm::getIsSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
	os << "Form: " << form.getName() << "\n";
	os << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n";
	os << "Grade to Sign: " << form.getGradeToSign() << "\n";
	os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
