#include "./include/Serializer.hpp"
#include "./include/Data.hpp"

int main(void) {
	Data *data = new Data(42);
	uintptr_t raw = Serializer::serialize(data);
	Data *data2 = Serializer::deserialize(raw);

	std::cout << "data: " << data->getN() << std::endl;
	std::cout << "data2: " << data2->getN() << std::endl;
	

	delete data;
	return 0;
}