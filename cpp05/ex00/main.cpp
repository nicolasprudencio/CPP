#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat *bureaucrat = new Bureaucrat("John", 2);
	Bureaucrat *bureaucrat2 = new Bureaucrat("Teddy", 150);

	std::cout << *bureaucrat << std::endl;
	std::cout << *bureaucrat2 << std::endl;

	try {
		bureaucrat->incrementGrade();
		bureaucrat2->decrementGrade();
	} catch (GradeTooLowException &e) {
        std::cout << e.what() << std::endl;
	} catch (GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << *bureaucrat << std::endl;
	delete bureaucrat;
	delete bureaucrat2;

	return 0;
}