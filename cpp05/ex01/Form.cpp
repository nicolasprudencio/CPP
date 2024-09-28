#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(1), _gradeToExecute(1) {
	std::cout << "Form " << _name << " created." << std::endl;
}

Form::Form(const std::string name, int gradeToSign, int gradeToExecute)
	throw(GradeTooHighException, GradeTooLowException)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1) {
		std::cout << "Error at form create: " << std::endl;
		throw GradeTooHighException();
	} else if (gradeToSign > 150 || gradeToExecute > 150) {
		std::cout << "Error at form create: " << std::endl;
		throw GradeTooLowException();
	}
	std::cout << "Form " << _name << " created." << std::endl;
}

Form::~Form() {
	std::cout << _name << " destroyed." << std::endl;
}

Form::Form(const Form &other) 
	: _name(other._name), _isSigned(other._isSigned),_gradeToSign(other._gradeToSign),
	_gradeToExecute(other._gradeToExecute) {
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

void Form::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
	if (bureaucrat.getGrade() > _gradeToSign) {
		throw GradeTooLowException();
	}
	_isSigned = true;
}

bool Form::getIsSigned() const {
	return _isSigned;
}

std::ostream& operator<<(std::ostream& os, Form const& form) {
	os << "Form: " << form.getName() << "\n";
	os << "Signed: " << (form.getIsSigned() ? "Yes" : "No") << "\n";
	os << "Grade to Sign: " << form.getGradeToSign() << "\n";
	os << "Grade to Execute: " << form.getGradeToExecute() << std::endl;
	return os;
}

const char* Form::GradeTooHighException::what() const throw() {
	return "FORM: Grade is too high";
}

const char* Form::GradeTooLowException::what() const throw() {
	return "FORM: Grade is too low";
}