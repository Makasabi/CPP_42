#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include "colors.hpp"

template<typename T>
void	iter(T * array, size_t const len, void (*f_pointer)(T &)) {

	for (size_t i = 0; i < len; i++) {
		f_pointer(array[i]);
	}
}

template<typename T>
void	print(T &i) {

	static int iterNu = 0;
	std::cout << _GREYER << "Iteration Number " << iterNu++ << ":\t" << _END << i << std::endl;
}

#endif