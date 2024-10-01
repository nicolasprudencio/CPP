#include "../include/Data.hpp"

Data::Data(): _n(0) {
	std::cout << "Data default constructor called" << std::endl;
}

Data::Data(int n): _n(n) {
	std::cout << "Data parameterized constructor called" << std::endl;
}

Data::Data(Data const & src): _n(src.getN()) {
	std::cout << "Data copy constructor called" << std::endl;
}

Data::~Data() {
	std::cout << "Data destructor called" << std::endl;
}

Data & Data::operator=(Data const & src) {
	std::cout << "Data assignment operator called" << std::endl;
	if (this != &src) {
		this->_n = src.getN();
	}
	return *this;
}

int Data::getN() const {
	return this->_n;
}