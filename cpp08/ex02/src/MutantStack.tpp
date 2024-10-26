#include "../includes/MutantStack.hpp"

template <typename T> MutantStack<T>::MutantStack(): std::stack<T>() {}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other): std::stack<T>(other) {}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(const MutantStack &other)
{
	if (this == &other)
		return (*this);
	std::stack<T>::operator=(other);
	return (*this);
}

template <typename T>
MutantStack<T>::~MutantStack() {}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{ return (std::stack<T>::c.begin()); }

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{ return (std::stack<T>::c.end()); }