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

void Span::addNumber(int n) {
	if (_size < _n) {
		_vec.push_back(n);
		this->_size = this->_size + 1;
	} else {
		throw std::overflow_error("Add number: no more space");
	}
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

unsigned int Span::getSize() const {
	return this->_n;
}

std::vector<int> Span::getVec() const {
	return this->_vec;
}

void Span::setVec(std::vector<int> other) {
	this->_vec = other;
}
