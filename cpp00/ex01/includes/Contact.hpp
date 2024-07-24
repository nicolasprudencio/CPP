#include <iostream>
#include <iomanip>
#include <string>

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

public:
	Contact();
	
	~Contact();

	void setContact(
		const std::string& firstName,
		const std::string& lastName,
		const std::string& nickname,
		const std::string& phoneNumber,
		const std::string& darkestSecret);
	
	void displayContact();

	void displayShort(int index);
	
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

	std::string truncate(const std::string& str) const {
		if (str.length() > 10) {
			return str.substr(0, 9) + ".";
		}
		return str;
	}
};

#endif