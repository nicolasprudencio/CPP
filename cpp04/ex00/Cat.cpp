#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat is born" << std::endl;
	_type = "Cat";
}

Cat::Cat(Cat &other) {
	std::cout << "Cat copy constructor" << std::endl;
	*this = other;
}

Cat::~Cat() {
	std::cout << "Cat was de americanas" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow Meow" << std::endl;
}

Cat &Cat::operator=(Cat &other) {
	std::cout << "Cat copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}