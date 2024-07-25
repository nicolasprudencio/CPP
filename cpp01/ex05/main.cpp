/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 21:45:55 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/24 21:46:31 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Harl.hpp"

int main() {
	Harl harl;

	std::cout << "Testing DEBUG level:" << std::endl;
	harl.complain("DEBUG");

	std::cout << "Testing INFO level:" << std::endl;
	harl.complain("INFO");

	std::cout << "Testing WARNING level:" << std::endl;
	harl.complain("WARNING");

	std::cout << "Testing ERROR level:" << std::endl;
	harl.complain("ERROR");

	std::cout << "Testing INVALID level:" << std::endl;
	harl.complain("INVALID");

	return 0;
}