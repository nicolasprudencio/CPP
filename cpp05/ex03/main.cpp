#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main() {
	Bureaucrat bureaucrat("John Doe", 1);
	Intern intern;
	AForm *formRobotomy = intern.makeForm("robotomy request" ,"robotomando");
	AForm *formShrubbery = intern.makeForm("shrubbery creation" ,"shrubbando");
	AForm *formPardon = intern.makeForm("presidential pardon","perdoando");
	AForm *formUnknow = intern.makeForm("unknown","perdoando");

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
	delete formUnknow;

	return 0;
}
