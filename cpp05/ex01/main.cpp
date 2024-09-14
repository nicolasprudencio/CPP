#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
	try {
		Bureaucrat alice("Alice", 50);
		
		Form formToSign("Form to Sign", 60, 25);   
		Form formNotSign("Form Not Sign", 40, 25); 
		
		std::cout << "Alice tenta assinar os formulários:" << std::endl;
		alice.signForm(formToSign);   
		alice.signForm(formNotSign);  
		
		std::cout << "\nStatus dos formulários:" << std::endl;
		std::cout << formToSign;
		std::cout << formNotSign;
	} catch (std::exception &e) {
		std::cerr << "Erro: " << e.what() << std::endl;
	}

	return 0;
}
