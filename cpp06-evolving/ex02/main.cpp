#include "./include/Base.hpp"
#include "./include/A.hpp"
#include "./include/B.hpp"
#include "./include/C.hpp"

int main(void) {
	Base *base = generate();
	Base *b = new B();
	Base *c = new C();
	B *derived;

	derived = dynamic_cast<B*>(b);
	if (derived == (void *)0)
		std::cerr << "ERRO: derived = dynamic_cast<B*>(b)" << std::endl;
	derived = dynamic_cast<B*>(c);
	if (derived == 0)
		std::cerr << "ERRO: derived = dynamic_cast<B*>(c)" << std::endl;
	identify(base);
	identify(*base);
	delete base;
	delete b;
	delete c;
	return 0;
}