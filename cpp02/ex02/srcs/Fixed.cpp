/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 22:26:19 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/24 22:33:46 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

// Constructors
Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue) {
	std::cout << "Int constructor called" << std::endl;
	this->value = intValue << fractionalBits;
}

Fixed::Fixed(const float floatValue) {
	std::cout << "Float constructor called" << std::endl;
	this->value = roundf(floatValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

// Destructor
Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

// Assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		this->value = other.value;
	}
	return *this;
}

// Member functions
int Fixed::getRawBits(void) const {
	return this->value;
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(this->value) / (1 << fractionalBits);
}

int Fixed::toInt(void) const {
	return this->value >> fractionalBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->value + other.value);
	return result;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed result;
	result.setRawBits(this->value - other.value);
	return result;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->value * other.value) >> fractionalBits);
	return result;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed result;
	result.setRawBits((this->value << fractionalBits) / other.value);
	return result;
}

// Comparison operators
bool Fixed::operator>(const Fixed &other) const {
	return this->value > other.value;
}

bool Fixed::operator<(const Fixed &other) const {
	return this->value < other.value;
}

bool Fixed::operator>=(const Fixed &other) const {
	return this->value >= other.value;
}

bool Fixed::operator<=(const Fixed &other) const {
	return this->value <= other.value;
}

bool Fixed::operator==(const Fixed &other) const {
	return this->value == other.value;
}

bool Fixed::operator!=(const Fixed &other) const {
	return this->value != other.value;
}

// Increment and Decrement operators
Fixed &Fixed::operator++() {
	this->value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	++(*this);
	return temp;
}

Fixed &Fixed::operator--() {
	this->value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	--(*this);
	return temp;
}

// Static member functions
Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b) ? a : b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b) ? a : b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b) ? a : b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b) ? a : b;
}

// Friend functions
std::ostream &operator<<(std::ostream &os, const Fixed &fixed) {
	os << fixed.toFloat();
	return os;
}
