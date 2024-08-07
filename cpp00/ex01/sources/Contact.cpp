#include "../includes/Contact.class.hpp"

Contact::Contact() {}
Contact::~Contact() {}

void Contact::setContact(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& nickname,
		const std::string& phoneNumber,
		const std::string& darkestSecret) 
	{
		_firstName = firstName;
		_lastName = lastName;
		_nickname = nickname;
		_phoneNumber = phoneNumber;
		_darkestSecret = darkestSecret;
	}

void Contact::displayContact() {
	std::cout << "First Name: " << _firstName << "\n"
				<< "Last Name: " << _lastName << "\n"
				<< "Nickname: " << _nickname << "\n"
				<< "Phone Number: " << _phoneNumber << "\n"
				<< "Darkest Secret: " << _darkestSecret << "\n";
}

void Contact::displayShort(int index) {
	std::cout << std::setw(10) << index << "|"
				<< std::setw(10) << truncate(_firstName) << "|"
				<< std::setw(10) << truncate(_lastName) << "|"
				<< std::setw(10) << truncate(_nickname) << "\n";
}
