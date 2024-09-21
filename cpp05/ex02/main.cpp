#include <iostream>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

int main() {
	try {
		Bureaucrat bureaucrat("John Doe", 40);
		RobotomyRequestForm form("Target1");

		std::cout << form << std::endl;
		form.beSigned(bureaucrat);
		std::cout << "Form signed successfully." << std::endl;
		form.robotomizing(bureaucrat);

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
