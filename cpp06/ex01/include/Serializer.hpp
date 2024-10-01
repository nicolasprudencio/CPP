#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

class Data;


class Serializer {
	public:
		static uintptr_t serialize(Data *data);
		static Data* deserialize(uintptr_t raw);

	private:
		Serializer();
		Serializer(Serializer const & src);
		~Serializer();
		Serializer & operator=(Serializer const & src);
};

#endif