#include "Sample.class.hpp"

int main( void ) {

	Sample sample;
	Sample& i = sample;
	int	n = 42;
	char c = 'q';
	float z = 42.21;

	sample.bar(n);
	sample.bar(c);
	sample.bar(z);
	sample.bar(i);

	return 0;
}