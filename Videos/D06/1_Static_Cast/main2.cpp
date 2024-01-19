# include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};

class Unrelated {};

int main(void) {

	Child1 a;								// Reference value;

	Parent * b = &a;						// Implicit upcast --> Ok
	Parent * c = b;							// Implicit downcast --> HELL NO!
	Parent * d = static_cast<Child2 *>(b);	// Explicit downcast -> ok, I do it

	// Unrelated * e = static_cast< Unrelated *>(& a); // Explicit Conversion -> NO!

}

/* Class parent -> more generic than the class Child1 and Child2*/
/*
	Upcast = from parent to child
	Downcast = from child to parent --> Will have horrible consequences
*/