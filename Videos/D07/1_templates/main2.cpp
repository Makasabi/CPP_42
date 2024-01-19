#include <iostream>

// template<typename T, typename U>
template<typename T>
class	List {

public:

	List<T>(T const & content) {
		// ..code code code
	}

	List<T>(List<T> const & list) {
		// ..code code code
	}

	~List<T>(void) {
		// ..code code code
	}

	// ..code code code

private:

	T* 			_content;
	List<T>*	_next;
};

int main (void) {

	// List<int, int>		a(42, 21);
	List<int>		a(42);
	List<float>		b(3.14f);
	List<List<int>>	c(a);
}