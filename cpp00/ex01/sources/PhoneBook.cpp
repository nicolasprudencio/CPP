/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 22:34:37 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 21:34:07 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../includes/PhoneBook.hpp"
#include "../includes/Contact.hpp"

PhoneBook::PhoneBook() : _currentIndex(0), _size(0) {}
PhoneBook::~PhoneBook() {}

void PhoneBook::addContact(const Contact& contact) {
	_contacts[_currentIndex] = contact;
	_currentIndex = (_currentIndex + 1) % maxContacts;
	if (_size < maxContacts) {
		_size++;
	}
}

void PhoneBook::displayContacts() {
	std::cout << std::setw(10) << "Index" << "|"
	<< std::setw(10) << "First Name" << "|"
	<< std::setw(10) << "Last Name" << "|"
	<< std::setw(10) << "Nickname" << "\n";
	for (int i = 0; i < _size; ++i) {
		_contacts[i].displayShort(i + 1);
	}
}

void PhoneBook::displayContact(int index) {
	if (index > 0 && index <= _size) {
		_contacts[index - 1].displayContact();
	} else {
		std::cout << "Invalid index.\n";
	}
};