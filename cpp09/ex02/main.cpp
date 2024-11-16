#include "./includes/PmergeMe.hpp"
#include <sstream>
#include <string>
#include <limits>
#include <cstdlib>
#include <vector>


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
	std::deque<int> dequeContainer;

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

		int vecStart =  clock();
		PmergeMe::fordJhonson<std::vector<int>, std::vector<std::pair<int, int> > >(vectorContainer);
		int vecFinish = clock();

		int lstStart =  clock();
		PmergeMe::fordJhonson<std::deque<int>, std::deque<std::pair<int, int> > >(dequeContainer);
		int lstFinish = clock();

		std::cout << "vector: " << double(vecFinish - vecStart) / CLOCKS_PER_SEC << std::endl;
		std::cout << "deque: " << double(lstFinish - lstStart) / CLOCKS_PER_SEC << std::endl;

	} catch (const std::invalid_argument &e) {
		std::cout << e.what() << std::endl;
		return 1;
	}
}