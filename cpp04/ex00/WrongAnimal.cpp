#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout << "WrongAnimal constructor called" << std::endl;
	this->_type = "Default WrongAnimal type";
	return;
}

WrongAnimal::WrongAnimal(WrongAnimal &Other) {
	std::cout << "WrongAnimal copy constructor" << std::endl;
	*this = Other;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal &other) {
	std::cout << "WrongAnimal copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string WrongAnimal::getType() const {
	std::cout << "type: ";
	return _type;
}

void WrongAnimal::makeSound() const {
	std::cout << "Barulhão pipocando de um WrongAnimal suspeito" << std::endl;
}
