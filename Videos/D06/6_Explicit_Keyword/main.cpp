#include <iostream>

class A {};
class B {};

class C {

public:

				C(A const & _) {return;}
	explicit	C(B const & _) {return;} // Forbid implicit construction of class 
};

void	f( C const & _) {
	return ;
}

int main (void) {
	f(A()); // Implicit conversion Ok
	// f(B()); // Implicit conversion --> NOT OK, constructor should be explicit

	return 0;
}