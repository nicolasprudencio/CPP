/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nicolas <nicolas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 00:32:29 by nicolas           #+#    #+#             */
/*   Updated: 2024/07/23 21:33:33 by nicolas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "./Contact.hpp"

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

class PhoneBook {
public:
	PhoneBook();
	~PhoneBook();


	void addContact(const Contact& contact);

	void displayContacts();

	void displayContact(int index);

	private:
		static const int maxContacts = 8;
		Contact _contacts[maxContacts];
		int _currentIndex;
		int _size;
};

#endif