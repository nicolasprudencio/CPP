#ifndef MUTANT_STACK_HPP
# define MUTANT_STACK_HPP

#include <stack>


template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		MutantStack &operator=(const MutantStack &other);
		~MutantStack() {}

		// typedef typename std::stack<T>::container_type::iterator iterator;
		// iterator begin() { return (std::stack<T>::c.begin()); }
		// iterator end() { return (std::stack<T>::c.end()); }
};

#include "../src/MutantStack.tpp"

#endif