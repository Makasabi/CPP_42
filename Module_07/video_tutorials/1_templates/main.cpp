#include <iostream>

/*
template<typename T> // type T can be whatever we want
T const	&	max(T const & x, T const & y) {
	return (x>=y? x : y);
}

// operator can have be overloaded -> can be a an object from a class
// hence using a reference to an object insted of a copy of an object
// using const since we won't modify any of the objects and return an unchanged ref of object.
*/

template<typename T> // type T can be whatever we want
T	max(T const & x, T const & y) {
	return (x>=y? x : y);
}

int		foo(int x) {

	std::cout << "Long computing tine" << std::endl;
	return x;
}

int main(void) {

	int		a	= 21;
	int		b	= 42;

	std::cout << "Max of " << a << " and " << b << " is ";
	std:: cout << max<int>(a, b) << std::endl;		// Explicit instanciation of the function 'max'
	std::cout << "Max of " << a << " and " << b << " is ";
	std:: cout << max(a, b) << std::endl;			// Implicit instanciation of the function 'max'

	float	c	= -1.7f;
	float	d	= 4.2f;

	std::cout << "Max of " << c << " and " << d << " is ";
	std:: cout << max<float>(c, d) << std::endl;		// Explicit instanciation
	std::cout << "Max of " << c << " and " << d << " is ";
	std:: cout << max(c, d) << std::endl;		// Implicit instanciation

	char	e	= 'a' ;
	char	f	= 'z' ;

	std::cout << "Max of " << e << " and " << f << " is ";
	std:: cout << max<char>(e, f) << std::endl;		// Explicit instanciation
	std::cout << "Max of " << e << " and " << f << " is ";
	std:: cout << max(e, f) << std::endl;		// Implicit instanciation

	//no problem here......

	int ret = max<int>(foo(a), foo(b));
	std::cout << "Max of " << a << " and " << b << " is ";
	std::cout << ret << std::endl;

}