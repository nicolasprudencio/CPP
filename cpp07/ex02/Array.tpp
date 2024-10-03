#include "Array.hpp"

template <typename T>
Array<T>::Array() : elements(NULL), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : len(n) {
	if (n == 0)
		elements = NULL;
	else
		elements = new T[n]();
}

template <typename T>
Array<T>::Array(const Array& other) : len(other.len) {
	if (len == 0) {
		elements = NULL;
	} else {
		elements = new T[len];
		for (unsigned int i = 0; i < len; i++) {
			elements[i] = other.elements[i];
		}
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
	if (this != &other) {
	
		delete[] elements;

	
		len = other.len;
		if (len == 0) {
			elements = NULL;
		} else {
			elements = new T[len];
			for (unsigned int i = 0; i < len; i++) {
				elements[i] = other.elements[i];
			}
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] elements;
}

template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= len) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= len) {
		throw std::out_of_range("Index out of bounds");
	}
	return elements[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return len;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr) {
	for (unsigned int i = 0; i < arr.size(); i++) {
		os << arr[i] << " ";
	}
	return os;
}