#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>
#include <iostream>

template <typename T>
class Array {
	private:
		T* elements;
		unsigned int len;

	public:

		Array();
		Array(unsigned int n);
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();

		const T& operator[](unsigned int index) const;
		T& operator[](unsigned int index);
		unsigned int size() const;
};

template <typename T>
std::ostream& operator<<(std::ostream& os, const Array<T>& arr);
#include "Array.tpp"

#endif
