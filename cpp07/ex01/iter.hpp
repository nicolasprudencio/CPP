#ifndef ITER_HPP
#define ITER_HPP

#include <string>

template <typename T>

void iter(T *array, int length, void (*f)(T &p)) {
	for (int i = 0; i < length; i++) {
		f(array[i]);
	}
}

template <typename T>

void print(T &value) {
	std::cout << value << std::endl;
}

void increment(int &i) {
	i += 1;
}

#endif