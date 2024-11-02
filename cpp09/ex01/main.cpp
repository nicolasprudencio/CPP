#include <iostream>
#include <sstream>

std::stringstream validateInputArgument(const std::string &arg)
{
	int memberCounter = 0;
	int spaceCounter = 0;
	std::stringstream ss(arg);
	std::string token;

	while (getline(ss, token, ' '))
	{
		bool isValidOperator = token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/';
		if (token.length() != 1 || (!std::isdigit(token[0]) && !isValidOperator))
			throw std::invalid_argument("Error: invalid input arg: " + token);
		std::cout << token << std::endl;
	}
	for (size_t i = 0; i < arg.length(); i++)
		spaceCounter++;
	if (memberCounter - spaceCounter != 1)
		throw std::invalid_argument("Error: invalid input arg");
	return ss;
}



int main(int argc, char **argv)
{
	if (argc != 2) {
		std::cerr << "Usage: ./rpn [input file]" << std::endl;
		return 1;
	}

	try {
		validateInputArgument(argv[1]);
	} catch (const std::invalid_argument &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
}