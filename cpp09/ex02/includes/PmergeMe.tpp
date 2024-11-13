#include "PmergeMe.hpp"
#include <limits>
#include <vector>

template <typename T>
void printPairContainer(T &container) {
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
		std::cout << it->first << " " << it->second << std::endl;
}

template <typename SimpleT>
void printContainer(SimpleT &container) {
	for (typename SimpleT::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << std::endl;
}


template <typename PairT>
void sortPairs(PairT &container) {
	typename PairT::iterator auxIt;
	// int firstValue;
	// int secondValue = std::numeric_limits<int>::max();

	for (typename PairT::iterator it = container.begin(); it != container.end(); it++)
	{
		if (it->first > it->second)
			std::swap(it->first, it->second);
	}
	for (typename PairT::iterator it = container.begin(); it != container.end(); it++)
	{
		auxIt = it;
		for (typename PairT::iterator it2 = it; it2 != container.end(); it2++)
		{
			if (it2->second < auxIt->second)
				auxIt = it2;
		}
		std::swap(it->first, auxIt->first);
		std::swap(it->second, auxIt->second);
	}
}

template <typename SimpleT, typename PairT>
void splitOrderedElements(PairT& container, SimpleT& orderedContainer, SimpleT& unoredContainer) {
	printPairContainer(container);
	std::cout << "--------PairContainer--------" << std::endl;
	for (typename PairT::iterator it = container.begin(); it != container.end(); it++)
	{
			orderedContainer.push_back(it->second);
			unoredContainer.push_back(it->first);
	}
	
}

template <typename SimpleT, typename PairT>
void createPairContainer(SimpleT& container, PairT& pairContainer) {
	for (typename SimpleT::iterator it = container.begin(); it != container.end(); it++)
	{
		int value = *it;
		pairContainer.push_back(std::make_pair(value, *(++it)));
	}

}


template <typename SimpleT, typename PairT>
std::vector<int> PmergeMe::generateBilola(int maxIndex, SimpleT cont) {
	std::vector<int> sequence;
	sequence.push_back(0);
	sequence.push_back(1);
	(void)cont;
	while (sequence.back() < maxIndex) {
		int nextValue = sequence.back() + 2 * sequence[sequence.size() - 2];
		if (nextValue >= maxIndex) break;
		sequence.push_back(nextValue);
	}
	return sequence;
};

template <typename SimpleT, typename PairT>
void PmergeMe::fordJhonson(SimpleT &container) {
	int lastValue = -1;
	PairT pairContainer;
	SimpleT orderedContainer;
	SimpleT pendingList;

	if (container.size() % 2 != 0)
	{
		lastValue = container.back();
		container.pop_back();
	}
	createPairContainer(container, pairContainer);
	sortPairs(pairContainer);
	splitOrderedElements(pairContainer, orderedContainer, pendingList);
	printContainer(orderedContainer);
	std::cout << "----------------" << std::endl;
	printContainer(pendingList);

	std::vector<int> jacobsthalIndices = generateBilola(pendingList.size(), orderedContainer);
	for (int i = jacobsthalIndices.size() - 1; i >= 0; --i) {
		size_t index = jacobsthalIndices[i];
		if (index < pendingList.size()) {
			typename SimpleT::iterator insertPos = std::lower_bound(orderedContainer.begin(), orderedContainer.end(), pendingList[index]);
			orderedContainer.insert(insertPos, pendingList[index]);
		}
	}


	if (lastValue != -1) {
		typename SimpleT::iterator insertPos = std::lower_bound(orderedContainer.begin(), orderedContainer.end(), lastValue);
		orderedContainer.insert(insertPos, lastValue);
	}

	printContainer(orderedContainer);
};