#include "./includes/PmergeMe.hpp"
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>
#include <list>


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

#include <deque>

int main(int argc, char **argv)
{
	std::vector<int> vectorContainer;
	std::deque<int> listContainer;

	// std::cout << argc << std::endl;
	if (argc <= 1) {
		std::cout << "Usage: ./pmergeme 1 2 3 4 5..." << std::endl;
		return 1;
	}
	try {
		for (int i = 1; i < argc; i++)
		{
			int nb = isValidInput(argv[i]);
			vectorContainer.push_back(nb);
			listContainer.push_back(nb);
		}
		PmergeMe::fordJhonson<std::vector<int>, std::vector<std::pair<int, int> > >(vectorContainer);
		PmergeMe::fordJhonson<std::deque<int>, std::deque<std::pair<int, int> > >(listContainer);

	} catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}