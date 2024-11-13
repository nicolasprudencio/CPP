#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <algorithm>
# include <vector>

class PmergeMe {
	public:
		PmergeMe();
		~PmergeMe();

		template <typename SimpleT, typename PairT>
		static void fordJhonson(SimpleT &container);
		template <typename SimpleT, typename PairT>
		static std::vector<int> generateBilola(int maxIndex, SimpleT cont);
	private:
		PmergeMe(const PmergeMe &obj);
		PmergeMe &operator=(const PmergeMe &obj);
	
};


# include "PmergeMe.tpp"

#endif