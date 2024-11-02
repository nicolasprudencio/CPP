#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>

class RPN {
	public:
		RPN();
		~RPN();

		static void calculateRPN(std::stack<int> &stack);
		static std::stack<int> fillStack(std::string &str);
	private:
		RPN(const RPN &obj);
		RPN &operator=(const RPN &obj);
	
};

#endif