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

		void addNumber(int n);
		int shortestSpan();
		int longestSpan();
		unsigned int getSize() const;
		std::vector<int> getVec() const;
		void setVec(std::vector<int> other);
};


#endif