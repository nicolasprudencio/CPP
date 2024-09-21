#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor called" << std::endl;
	this->_type = "Default animal type";
	return;
}

Animal::Animal(Animal &Other) {
	std::cout << "Animal copy constructor" << std::endl;
	*this = Other;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal &Animal::operator=(Animal &other) {
	std::cout << "Animal copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

std::string Animal::getType() const {
	std::cout << "type: ";
	return _type;
}

void Animal::makeSound() const {
	std::cout << "Barulhão pipocando de um animal suspeito" << std::endl;
}
