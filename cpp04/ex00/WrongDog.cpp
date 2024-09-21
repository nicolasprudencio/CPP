#include "WrongDog.hpp"

WrongDog::WrongDog() {
	std::cout << "WrongDog is born" << std::endl;
	_type = "WrongDog";
}

WrongDog::WrongDog(WrongDog &other) {
	std::cout << "WrongDog copy constructor" << std::endl;
	*this = other;
}

WrongDog::~WrongDog() {
	std::cout << "WrongDog was de americanas" << std::endl;
}

WrongDog &WrongDog::operator=(WrongDog &other) {
	std::cout << "WrongDog copy assignment operator" << std::endl;
	if (this != &other) {
		_type = other._type;
	}
	return *this;
}

void WrongDog::makeSound() const {
	std::cout << "Woof woof!" << std::endl;
}