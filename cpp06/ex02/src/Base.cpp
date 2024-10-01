#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"
#include <cmath>
#include <stdexcept>


Base::~Base() {
	std::cout << "Base destructor called" << std::endl;
}

Base*	generate(void) {
	srand(time(NULL));
	int i = rand() % 3;

	switch(i) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		case 3:
			
		default:
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
	} else if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
	} else if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
	} else {
		std::cout << "Error: unknown type" << std::endl;
	}
}


void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	} catch (std::exception &e) {
		try {
			B &b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << "B" << std::endl;
		} catch (std::exception &e) {
			try {
				C &c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << "C" << std::endl;
			} catch (std::exception &e) {
				std::cout << "Error: unknown type" << std::endl;
			}
		}
	}
}