#include <iostream>
#include <typeinfo>
#include <exception>

class Parent			{public: virtual ~Parent(void) {} };
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void) {

	Child1		a;			// Reference;
	Parent *	b = &a;		// Implicit upcast -> ok

	// Explicit downcast to real type (Child1)-> suspens ....
	Child1 *	c = dynamic_cast<Child1 *>(b);
	if (c == NULL) {
		std::cout << "Conversion is NOT OK" << std::endl;
	}
	else { 
		std::cout << "Conversion is OK" << std::endl;
	}

	// Explicit downcast to other type (Child2)-> suspens ....
	try {
		Child2 &	d = dynamic_cast<Child2 &>(*b);
		std::cout << "Conversion is OK" << std::endl;
	}
	catch (std::bad_cast &bc) {
		std::cout << "Conversion is NOT OK: " << bc.what() << std::endl;
		return 0;
	}
	return 0;

}

/* 
--> Dynamic cast used ONLY in case of DOWNCAST
--> Dynamic cast only wotrk with pointer or reference
*/