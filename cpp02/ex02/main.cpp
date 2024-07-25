/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:27:49 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/24 22:34:16 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/Fixed.hpp"

int main(void) {
	Fixed a;
	Fixed const b(Fixed(5.05f) * Fixed(2));

	std::cout << a << std::endl; // Expect 0
	std::cout << ++a << std::endl; // Expect 0.00390625 (smallest increment)
	std::cout << a << std::endl; // Expect 0.00390625
	std::cout << a++ << std::endl; // Expect 0.00390625 (value before increment)
	std::cout << a << std::endl; // Expect 0.0078125 (value after increment)
	std::cout << b << std::endl; // Expect 10.1016

	Fixed const c(42.42f);
	std::cout << Fixed::max(a, b) << std::endl; // Expect 10.1016 (b is greater than a)

	return 0;
}
