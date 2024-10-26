#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <iostream>

class Span {
	private:
		unsigned int _n;
		unsigned int _size;
		std::vector<int> _vec;
	public:
		Span(unsigned int size);
		Span(Span const & src);
		~Span();
		Span & operator=(Span const & src);

		std::vector<int> getVec() const;
		void addNumber(int n);
		void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		int shortestSpan();
		int longestSpan();
};

std::ostream &operator<<(std::ostream &os, Span const &src);




#endif