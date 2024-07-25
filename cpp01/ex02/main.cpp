/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 23:11:29 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 23:13:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main() {

	std::string brain = "HI THIS IS BRAIN";

	std::string* stringPTR = &brain;

	std::string& stringREF = brain;

	std::cout << "Memory address of the string variable: " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR: " << stringPTR << std::endl;
	std::cout << "Memory address held by stringREF: " << &stringREF << std::endl;

	std::cout << "Value of the string variable: " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF: " << stringREF << std::endl;

	return 0;
}

// std::string brain = "HI THIS IS BRAIN";: This creates a string variable named brain and initializes it with the given value.
// Pointer:

// std::string* stringPTR = &brain;: This creates a pointer named stringPTR that holds the address of the brain string variable.
// Reference:

// std::string& stringREF = brain;: This creates a reference named stringREF to the brain string variable. A reference is an alias for the original variable.