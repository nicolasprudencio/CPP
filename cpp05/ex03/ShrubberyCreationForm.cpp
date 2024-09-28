#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
	std::cout << "ShrubberyCreationForm constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other) {
	*this = other;
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

void ShrubberyCreationForm::ShrubberyingFile() const{
	std::string fileName = _target + "_shrubbery";
	std::ofstream file;


	file.open(fileName.c_str());
	if (!file.is_open()) {
		std::cerr << "ERROR: Couldn't open file " << fileName << std::endl;
		return ;
	}
	file << REAL_SHRUBBERY << std::endl;
	file.close();
}

void ShrubberyCreationForm::execute(Bureaucrat const& executor) const
throw (GradeTooLowException, GradeTooHighException, FormIsNotSignedException) {
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	if (!getIsSigned())
		throw FormIsNotSignedException();
	ShrubberyingFile();
}
