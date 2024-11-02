#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <algorithm>

class RPN {
	public:
		RPN();
		~RPN();

		static void validateInputArgument(const std::string &arg);
		static int calculate(const std::string &input);
		static void rpnCalculator(std::stack<int> &stack, char token);
	private:
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
	
};

#endif