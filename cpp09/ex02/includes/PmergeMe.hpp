#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		template <typename T, typename containerT>
		static void fordJhonson(T &container);
	private:
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
	
};

# include "PmergeMe.tpp"

#endif