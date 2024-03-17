# include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main(void) {

	Child1 a;						// Reference value;

	Parent * b = &a;				// Implicit 'reinterpretation' cast
	Parent * c = (Parent * ) &a;	// Explicit 'reinterpretation' cast

	Parent * d = &a;				// Explicit upcast -> OK
	// Child1 * e = d;					// Implicit downcast -> Hell no !
	Child2 * f = (Child2 *) d;		// Explicit downcast -> Ok, but really ?

}

/* Class parent -> more generic than the class Child1 and Child2*/
/*
	Upcast = from parent to child
	Downcast = from child to parent --> Will have horrible consequences
*/