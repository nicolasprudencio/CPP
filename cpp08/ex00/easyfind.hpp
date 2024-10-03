#ifndef EASYFIND_HPP
# define EASYFIND_HPP

class NotFoundException : public std::exception {
	public:
		const char* what() const throw();
};

template <typename T>
typename T::iterator easyfind(T& container, int value);

#include "easyfind.tpp"

#endif