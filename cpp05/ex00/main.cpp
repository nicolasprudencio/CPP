#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat bureaucrat("John", 2);
	Bureaucrat bureaucrat2("Teddy", 149);

	// try {
	// 	Bureaucrat bureaucrat3("order", 0);
	// } catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	// try {
	// 	Bureaucrat bureaucrat4("last", 151);
	// } catch (Bureaucrat::GradeTooLowException &e) {
	// 	std::cout << e.what() << std::endl;
	// } catch (Bureaucrat::GradeTooHighException &e) {
	// 	std::cout << e.what() << std::endl;
	// }

	std::cout << bureaucrat << std::endl;
	std::cout << bureaucrat2 << std::endl;

	try {
		bureaucrat.incrementGrade();
		std::cout << bureaucrat.getName() << std::endl;
		bureaucrat2.decrementGrade();
		// bureaucrat2.decrementGrade();
		// bureaucrat2.decrementGrade();
	} catch (Bureaucrat::GradeTooLowException &e) {
		std::cout << e.what() << std::endl;
	} catch (Bureaucrat::GradeTooHighException &e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << bureaucrat << std::endl;

	return 0;
}