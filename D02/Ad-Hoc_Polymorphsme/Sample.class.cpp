#include "Sample.class.hpp"

Sample::Sample (void) {

	std::cout << "Constructor called" << std::endl;
}

Sample::~Sample (void) {

	std::cout << "Destructor called" << std::endl;
}

void	Sample::bar (char const c)const {

	std::cout << "Member function called with char overload : " << c << std::endl;
}

void	Sample::bar (int const n)const {

	std::cout << "Member function called with int overload : " << n << std::endl;
}

void	Sample::bar (float const z)const {

	std::cout << "Member function called with float overload : " << z << std::endl;
}

void	Sample::bar (Sample const & i)const {

	(void) i;
	std::cout << "Member function called with Sample class overload" << std::endl;
}