#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade): _name(name) {
	if (grade < 1) {
		throw GradeTooHighException();
	} else if (grade > 150) {
		throw GradeTooLowException();
	}
	_grade = grade;
	std::cout << "Bureaucrat " << _name << " created" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat &other) {
	*this = other;
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
}


Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat " << _name << " destroyed" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat &other) {
	std::cout << "Bureaucrat Copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

void Bureaucrat::incrementGrade() throw(GradeTooHighException) {
	if (_grade == 1) {
		throw GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::decrementGrade() throw(GradeTooLowException) {
	if (_grade == 150) {
		throw GradeTooLowException();
	}
	_grade++;
}

void Bureaucrat::signForm(AForm &form) {
	try {
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	} catch (std::exception &e) {
		std::cout << _name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& bureaucrat) {
	os << "Bureaucrat " << bureaucrat.getName() << " has grade " << bureaucrat.getGrade();
	return os;
}
