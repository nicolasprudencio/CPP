#include "PmergeMe.hpp"
#include <limits>
#include <vector>


template <typename SimpleT>
void printContainer(SimpleT &container) {
	for (typename SimpleT::iterator it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}


template <typename PairT>
void sortPairs(PairT &container) {
	typename PairT::iterator auxIt;

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

template <typename SimpleT>
void PmergeMe::mergeInsertion(SimpleT& orderedContainer, SimpleT& pendingList)
{
	SimpleT jacobsthalIndices = generateJacobSequence<SimpleT>(pendingList.size());

	for (int i = jacobsthalIndices.size() - 1; i >= 0; --i)
	{
		size_t index = jacobsthalIndices[i];
		if (index < pendingList.size()) 
		{
			typename SimpleT::iterator insertPos = std::lower_bound(
				orderedContainer.begin(), orderedContainer.end(), pendingList[index]
			);
			orderedContainer.insert(insertPos, pendingList[index]);
		}
	}

	for (size_t i = 0; i < pendingList.size(); ++i) {
		if (std::find(jacobsthalIndices.begin(), jacobsthalIndices.end(), i) == jacobsthalIndices.end()) {
			typename SimpleT::iterator insertPos = std::lower_bound(
				orderedContainer.begin(), orderedContainer.end(), pendingList[i]
			);
			orderedContainer.insert(insertPos, pendingList[i]);
		}
	}
}


template <typename SimpleT>
SimpleT PmergeMe::generateJacobSequence(int maxIndex) {
	SimpleT sequence;
	sequence.push_back(0);
	sequence.push_back(1);

	for (int i = 0; i < maxIndex; i++) {
		int nextValue = sequence.back() + (2 * sequence[sequence.size() - 2]);
		if (nextValue >= maxIndex) break;
		sequence.push_back(nextValue);
	}
	sequence.erase(std::unique(sequence.begin(), sequence.end()), sequence.end());
	return sequence;
};

template <typename SimpleT, typename PairT>
void PmergeMe::fordJhonson(SimpleT &container) {
	int lastValue = -1;
	PairT pairContainer;
	SimpleT orderedContainer;
	SimpleT pendingList;

	std::cout << "------------ Before ------------ " << std::endl;
	printContainer(container);

	if (container.size() % 2 != 0) {
		lastValue = container.back();
		container.pop_back();
	}
	createPairContainer(container, pairContainer);
	sortPairs(pairContainer);
	splitOrderedElements(pairContainer, orderedContainer, pendingList);
	mergeInsertion(orderedContainer, pendingList);


	if (lastValue != -1) {
		typename SimpleT::iterator insertPos = std::lower_bound(
			orderedContainer.begin(), orderedContainer.end(), lastValue
		);
		orderedContainer.insert(insertPos, lastValue);
	}

	std::cout << "------------ After ------------ " << std::endl;
	printContainer(orderedContainer);
}