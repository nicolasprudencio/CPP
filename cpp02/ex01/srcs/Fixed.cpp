/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:03:18 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/24 22:13:15 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Default constructor
Fixed::Fixed() : fixedPointValue(0) {
	std::cout << "Default constructor called" << std::endl;
}

// Int constructor
Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;
	this->fixedPointValue = value << fractionalBits;
}

// Float constructor
Fixed::Fixed(const float value) {
	std::cout << "Float constructor called" << std::endl;
	this->fixedPointValue = roundf(value * (1 << fractionalBits));
}

// Copy constructor
Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Copy assignment operator
Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->fixedPointValue = other.getRawBits();
	}
	return *this;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Getter for raw bits
int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->fixedPointValue;
}

// Setter for raw bits
void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->fixedPointValue = raw;
}

// Convert to float
float Fixed::toFloat(void) const {
	return static_cast<float>(this->fixedPointValue) / (1 << fractionalBits);
}

// Convert to int
int Fixed::toInt(void) const {
	return this->fixedPointValue >> fractionalBits;
}

// Overload of << operator
std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
