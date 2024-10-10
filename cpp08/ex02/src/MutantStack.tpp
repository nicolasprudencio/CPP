#include "../includes/MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack::MutantStack(const MutantStack &other): std::stack<T>(other) {}

template <typename T>
MutantStack &operator=(const MutantStack &other)
{
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
MutantStack::~MutantStack() {}