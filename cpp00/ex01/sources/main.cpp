#include <iostream>
#include <string>
#include "../includes/Contact.class.hpp"
#include "../includes/PhoneBook.class.hpp"
#include <limits> 

bool isValidPhoneNumber(const std::string& phoneNumber) {
	if (phoneNumber.length() < 8 || phoneNumber.length() > 11) {
		return false;
	}
	for (size_t i = 0; i < phoneNumber.length(); i++) {
		if (!std::isdigit(phoneNumber[i])) {
			return false;
		}
	}
	return true;
}

int main() {
	PhoneBook phoneBook;
	std::string command;

	while (true) {
		std::cout << "Enter command (ADD, SEARCH, EXIT): ";
		std::getline(std::cin, command);

		if (command == "ADD") {
			std::string firstName, lastName, nickname, phoneNumber, darkestSecret;

			std::cout << "Enter first name: ";
			std::getline(std::cin, firstName);
			if (firstName.empty()) continue;

			std::cout << "Enter last name: ";
			std::getline(std::cin, lastName);
			if (lastName.empty()) continue;

			std::cout << "Enter nickname: ";
			std::getline(std::cin, nickname);
			if (nickname.empty()) continue;

			std::cout << "Enter phone number: ";
			std::getline(std::cin, phoneNumber);
			if (phoneNumber.empty()) continue;
			if (!isValidPhoneNumber(phoneNumber)) {
				std::cerr << "Invalid phone number. It must be 8-11 digits long and contain only digits.\n";
				continue;
			}

			std::cout << "Enter darkest secret: ";
			std::getline(std::cin, darkestSecret);
			if (darkestSecret.empty()) continue;

			Contact newContact;
			newContact.setContact(firstName, lastName, nickname, phoneNumber, darkestSecret);
			phoneBook.addContact(newContact);
			std::cout << "Contact added successfully.\n";
		}
		else if (command == "SEARCH") {
			phoneBook.displayContacts();
			std::cout << "Enter index to display: ";
			int index;

			while (true) {
				if (std::cin >> index) {
					std::cin.ignore(); // Ignora o caractere de nova linha restante no buffer
					phoneBook.displayContact(index);
					break;
				} else {
					std::cin.clear(); // Limpa o erro de falha de leitura
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora o restante da linha
					std::cout << "Invalid index. Please enter a number: ";
				}
			}
		}
		else if (command == "EXIT") {
			break;
		} else {
			std::cout << "Invalid command.\n";
		}
	}

	return 0;
}
