#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		template <typename T>
		static void mergeMe(T &container);
	private:
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
	
};

template <typename T>
void PmergeMe::mergeMe(T &container) {
	typename T::iterator mid = container.begin() + container.size() / 2;
	std::sort(container.begin(), mid);
	for (typename T::iterator it = mid; it != container.end(); ++it) {
	// Encontra a posição onde o elemento deve ser inserido na primeira metade ordenada
		typename T::iterator pos = std::upper_bound(container.begin(), mid, *it);

	// Move o elemento para a posição correta (simulando uma inserção ordenada)
		int valor = *it;
		for (typename T::iterator i = it; i != pos; --i) {
			*i = *(i - 1);
		}
		*pos = valor;
	}
}

#endif