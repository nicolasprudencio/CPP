#ifndef DATA_HPP
# define DATA_HPP

#include <iostream>

class Data {
	public:
		Data();
		Data(int n);
		Data(Data const & src);
		~Data();
		Data & operator=(Data const & src);
		int getN() const;

	private:
		int _n;
};

#endif