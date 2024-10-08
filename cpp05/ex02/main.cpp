#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	Bureaucrat bureaucrat("John Doe", 1);
	AForm *formRobotomy = new RobotomyRequestForm("robotomando");
	AForm *formShrubbery = new ShrubberyCreationForm("shrubbando");
	AForm *formPardon = new PresidentialPardonForm("perdoando");

	std::cout << std::endl << *formRobotomy << std::endl;
	bureaucrat.executeForm(*formRobotomy);
	bureaucrat.signForm(*formRobotomy);
	bureaucrat.executeForm(*formRobotomy);
	std::cout << *formRobotomy << std::endl;

	
	std::cout << *formShrubbery << std::endl;
	bureaucrat.executeForm(*formShrubbery);
	bureaucrat.signForm(*formShrubbery);
	bureaucrat.executeForm(*formShrubbery);
	std::cout << *formShrubbery << std::endl;

	std::cout << *formPardon << std::endl;
	bureaucrat.executeForm(*formPardon);
	bureaucrat.signForm(*formPardon);
	bureaucrat.executeForm(*formPardon);
	std::cout << *formPardon << std::endl;

	delete formRobotomy;
	delete formShrubbery;
	delete formPardon;

	return 0;
}
