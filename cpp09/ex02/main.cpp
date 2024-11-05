#include "./includes/PmergeMe.hpp"
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <deque>

int isValidInput(std::string input)
{
	std::stringstream ss(input);
	std::string token;
	long number;

	while (getline(ss, token, ' '))
	{
		number = std::strtol(token.c_str(), NULL, 10);
		if (token.find_first_not_of("0123456789") != std::string::npos || std::numeric_limits<int>::max() < number || number < 0)
			throw std::invalid_argument("Error: invalid input argument");
	}
	return number;
}

int main(int argc, char **argv)
{
	std::vector<int> vectorContainer;
	std::deque<int> dequeContainer;

	std::cout << argc << std::endl;
	if (argc <= 1) {
		std::cout << "Usage: ./pmergeme 1 2 3 4 5..." << std::endl;
		return 1;
	}
	try {
		for (int i = 1; i < argc; i++)
		{
			int nb = isValidInput(argv[i]);
			vectorContainer.push_back(nb);
			dequeContainer.push_back(nb);
		}
		std::cout << "Before: " << std::endl;
		for (std::vector<int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		PmergeMe::mergeMe(vectorContainer);
		std::cout << "After: " << std::endl;
		for (std::vector<int>::iterator it = vectorContainer.begin(); it != vectorContainer.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		
	/* ---------------------------------------------------------*/


		std::cout << "Before: " << std::endl;
		for (std::deque<int>::iterator it = dequeContainer.begin(); it != dequeContainer.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
		PmergeMe::mergeMe(dequeContainer);
		std::cout << "After: " << std::endl;
		for (std::deque<int>::iterator it = dequeContainer.begin(); it != dequeContainer.end(); it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	} catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}