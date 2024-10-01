#include "../include/Serializer.hpp"

Serializer::Serializer() {
	std::cout << "Serializer default constructor called" << std::endl;
}

Serializer::Serializer(Serializer const & src) {
	std::cout << "Serializer copy constructor called" << std::endl;
	*this = src;
}

Serializer::~Serializer() {
	std::cout << "Serializer destructor called" << std::endl;
}

Serializer & Serializer::operator=(Serializer const & src) {
	std::cout << "Serializer assignment operator called" << std::endl;
	(void)src;
	return *this;
}

uintptr_t Serializer::serialize(Data *data) {
	return reinterpret_cast<uintptr_t>(data);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
