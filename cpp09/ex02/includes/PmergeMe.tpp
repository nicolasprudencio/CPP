#include "PmergeMe.hpp"
#include <limits>

template <typename T>
void printPairContainer(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

template <typename T>
void sortPairs(T &container) {
	typename T::iterator auxIt;
	int firstValue;
	int secondValue = std::numeric_limits<int>::max();

	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	// for (typename T::iterator it = container.begin(); it != container.end(); it++)
	// {
	// 	firstValue = it->first + it->second;
	// 	auxIt = it;
	// 	if (++it != container.end())
	// 		secondValue = it->first + it->second;
	// 	if (firstValue > secondValue)
	// 		std::swap(auxIt, it);
	// }
}

template <typename T, typename containerT>
void PmergeMe::fordJhonson(T &container) {
	int value = -1;
	containerT pairContainer;
	if (container.size() % 2 != 0)
	{
		value = container.back();
		container.pop_back();
	}
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		pairContainer.push_back(std::make_pair(*it, *(++it)));
	sortPairs(pairContainer);
	printPairContainer(pairContainer);
}