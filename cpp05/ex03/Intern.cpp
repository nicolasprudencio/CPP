#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern() {
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(Intern const& other) {
	std::cout << "Intern copy constructor" << std::endl;
	*this = other;
}

Intern::~Intern() {
	std::cout << "Intern destructor" << std::endl;
}

Intern& Intern::operator=(Intern const& other) {
	std::cout << "Intern copy assignment operator" << std::endl;
	if (this != &other) {
		(void)other;
	}
	return *this;
}

AForm* Intern::makeForm(std::string const& formName, std::string const& target) {
	std::string formNames[3] = {"robotomy request", "shrubbery creation", "presidential pardon"};
	int index = -1;

	for (size_t i = 0; i < 3; i++) {
		if (formName == formNames[i]) {
			index = i;
			break;
		}
	}
	
	switch(index)
	{
		case 0:
			std::cout << std::endl << "Intern: creates " << formName << std::endl;
			return new RobotomyRequestForm(target);
		case 1:
			std::cout << std::endl << "Intern: creates " << formName << std::endl;
			return new ShrubberyCreationForm(target);
		case 2:
			std::cout << std::endl << "Intern: creates " << formName << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << std::endl << "Intern: Form not found" << std::endl;
		return NULL;
	}
}
