#include "AAnimal.hpp"

AAnimal::AAnimal() {
	std::cout << "AAnimal constructor called" << std::endl;
	this->_type = "Default AAnimal type";
	return;
}

AAnimal::AAnimal(AAnimal &Other) {
	std::cout << "AAnimal copy constructor" << std::endl;
	*this = Other;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal &other) {
	std::cout << "AAnimal copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string AAnimal::getType() const {
	std::cout << "type: ";
	return _type;
}

void AAnimal::makeSound() const {
	std::cout << "Barulhão pipocando de um AAnimal suspeito" << std::endl;
}
