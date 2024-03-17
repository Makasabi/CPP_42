#include "Class.hpp"
#include "colors.hpp"
#include <time.h>
#include <cstdlib>

Base * generate(void) {

	Base * obj;
	srand(time(NULL));
	static int rnd = rand();

	rnd = rnd%3;
	switch (rnd) {
		case 0 :
			obj = new A;
			std::cout << "A Created" << std::endl;
			break;
		case 1 :
			obj = new B;
			std::cout << "B Created" << std::endl;
			break;
		case 2 :
			obj = new C;
			std::cout << "C Created" << std::endl;
			break;
		default :
			throw ErrorInstanciatingObj();
	}
	return obj;
}

void identify(Base* p) {

	A * testA = dynamic_cast<A *>(p);
	if (testA == NULL) {
		B * testB = dynamic_cast<B *>(p);
		if (testB == NULL )
			std::cout << _EMMERALD << "Type is C" <<_END <<std::endl;
		else
			std::cout << _RED << "Type is B" << _END  <<std::endl;
	}
	else
		std::cout << _BLUE << "Type is A" << _END <<std::endl;
	return;
}

void identify(Base& p) {

	try {
		A & testA = dynamic_cast<A &>(p);
		std::cout << _BLUE << "Type is A" << _END <<std::endl;
		(void)testA;
		return;
	}
	catch (...) {}

	try {
		B & testB = dynamic_cast<B &>(p);
		std::cout << _RED << "Type is B" << _END  <<std::endl;
		(void)testB;
		return;
	}
	catch (...) {}

	try {
		C & testC = dynamic_cast<C &>(p);
		std::cout << _EMMERALD << "Type is C" <<_END <<std::endl;
		(void)testC;
		return;
	}
	catch (...) {}

	std::cout << "class is unidentified" << std::endl;	
}

int main () {

	Base * obj;

	try {
		obj = generate();
		identify(obj);
		identify(*obj);
		delete obj;
	}
	catch (std::exception &e) {
		e.what();
	}

}