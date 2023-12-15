#ifndef Array_HPP
# define Array_HPP

# include <iostream>
# include <exception>
# include "colors.hpp"

template<typename T>
class Array
{

public:
	Array<T>(void ) : _array(new T[0]), _arrSize(0) {}

	Array<T>(unsigned int n) : _array(new T[n]), _arrSize(n) {}

	Array<T>(Array<T> const & src) {
		_arrSize = src.size();
		_array = new T[src.size()];
		for (size_t i = 0; i < _arrSize; i++){
			_array[i] = src._array[i];
		}
	}
	
	Array<T>& operator=(Array const & src) {
		if (this != &src) {
			delete [] _array;
			_arrSize = src.size();
			_array = new T(src.size());
			for (size_t i = 0; i < _arrSize; i++)
				_array[i] = src._array[i];
		}
		return *this;
	}

	~Array<T>() {delete [] _array;}

	T& operator[](size_t n) const {
		if (n >= this->_arrSize)
			throw OutOfArray();
		return(this->_array[n]);
	}

	size_t	size(void) const {return this->_arrSize;}

	class OutOfArray : public std::exception {
	public :
		virtual const char * what() const throw() {return _RED "Given index out of array bonds" _END;}
	};

private:
	T *		_array;
	size_t	_arrSize;
};

template<typename T>
std::ostream & operator<<(std::ostream & o, Array<T> const & p) {
	for (size_t i = 0; i < p.size() ; i++)
		o << "Array [" << i << "]: " << p[i] << "\n";
	return o;
}

#endif