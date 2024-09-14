#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1) {
		throw GradeTooHighToSignException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		throw GradeTooLowToSignException();
	}
	std::cout << "Form " << _name << " created." << std::endl;
}

Form::~Form() {
	std::cout << "Form " << _name << " destroyed." << std::endl;
}

Form::Form(const Form &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute) {
	std::cout << "Form Copy constructor called" << std::endl;
}

Form& Form::operator=(const Form &other) {
	std::cout << "Form Copy assignment operator called" << std::endl;
	if (this != &other) {
	
		this->_isSigned = other._isSigned;
	}
	return *this;
}

std::string Form::getName() const {
	return _name;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(Bureaucrat &bureaucrat) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
	std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
	os << "Form: " << form.getName() << "\n";
	os << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n";  // Usando getter
	os << "Grade to Sign: " << form.getGradeToSign() << "\n";
	os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
	return os;
}
