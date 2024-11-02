#include "../includes/RPN.hpp"

RPN::RPN() {}
RPN::~RPN() {}

RPN::RPN(const RPN &obj) {
	*this = obj;
}

RPN &RPN::operator=(const RPN &obj) {
	(void)obj;
	return *this;
}

void RPN::validateInputArgument(const std::string &arg, std::stringstream &ss)
{
	int memberCounter = 0;
	int operatorCounter = 1;
	int spaceCounter = std::count(arg.begin(), arg.end(), ' ');
	
	ss.str(arg);
	std::string token;

	if (arg.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::invalid_argument("Error: invalid input argument");

	while (getline(ss, token, ' '))
	{
		bool isValidOperator = token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0] == '/';
		if (token.length() != 1)
			throw std::invalid_argument("Error: invalid input argument: " + token);
		if (isValidOperator)
			operatorCounter++;
		memberCounter++;
		// std::cout << token << std::endl;
	}

	// std::cout << "space counter: " << spaceCounter << std::endl;
	if (memberCounter - spaceCounter != 1 || operatorCounter == 0)
		throw std::invalid_argument("Error: invalid input argument");
}

int RPN::calculate(const std::string &input, std::stack<int> &stack)
{
	std::string token;

	for (size_t i = 0; i < input.length(); i++)
	{
		if (std::isdigit(input[i])) {
			stack.push(atoi(std::string(1, input[i]).c_str()));
		} else if (input[i] != ' '){
			rpnCalculator(stack, input[i]);
		}
	}

	if (stack.size() != 1) {
		throw std::invalid_argument("Error: invalid input argument. The stack should have exactly one element at the end.");
	}

	return stack.top();
}

void RPN::rpnCalculator(std::stack<int> &stack, char token)
{
	int a;
	int b;

	if (stack.size() < 2)
		throw std::invalid_argument("Error: invalid input argument");

	b = stack.top();
	stack.pop();
	a = stack.top();
	stack.pop();

	if (token == '+')
		stack.push(a + b);
	else if (token == '-')
		stack.push(a - b);
	else if (token == '*')
		stack.push(a * b);
	else if (token == '/')
		stack.push(a / b);
}