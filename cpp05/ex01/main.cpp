#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
		Bureaucrat alice("Alice", 50);
		
		Form formToSign("Form to Sign", 60, 25);   
		Form formNotSign("Form Not Sign", 40, 25); 
		
		std::cout << std::endl << "Alice try to sign the forms:" << std::endl;
		alice.signForm(formToSign);
		alice.signForm(formNotSign);
		
		std::cout << std::endl << "Status of formularies:" << std::endl;
		std::cout << formToSign;
		std::cout << formNotSign;

	return 0;
}
