#include "../includes/Span.hpp"
#include <algorithm>
#include <limits>

Span::Span(unsigned int n): _n(n), _size(0) {}

Span::Span(Span const & other) {
	*this = other;
}

Span::~Span() {}

Span & Span::operator=(Span const & other) {
	if (this != &other) {
		this->_n = other._n;
		this->_vec = other._vec;
	}
	return *this;
}

std::vector<int> Span::getVec() const {
	return _vec;
}

void Span::addNumber(int n) {
	if (_size < _n) {
		_vec.push_back(n);
		this->_size = this->_size + 1;
	} else {
		throw std::overflow_error("Add number: no more space for adding numbers");
	}
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	for (std::vector<int>::iterator it = begin; it != end; ++it) 
		addNumber(*it);
}


int Span::shortestSpan() {
	if (_size < 2) {
		throw std::logic_error("Shortest span: not enough numbers");
	}
	int min;
	std::vector<int> _aux;

	_aux = _vec;
	min = std::numeric_limits<int>::max();
	sort(_aux.begin(), _aux.end());
	for (unsigned int i = 0; i < _size - 1; i++) {
		if (_aux[i + 1] - _aux[i] < min) {
			min = _aux[i + 1] - _aux[i];
		}
	}
	return min;
}

int Span::longestSpan() {
	if (_size < 2) {
		throw std::logic_error("Longest span: not enough numbers");
	}
	std::vector<int> aux = _vec;
	sort(aux.begin(), aux.end());
	return aux[aux.size() - 1] - aux[0];
}

std::ostream  &operator<<(std::ostream &os, Span const &src) {

	std::vector<int> vec = src.getVec();

	os << "Numbers: ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it)
		os << *it << " ";
	os << std::endl;
	return os;
}