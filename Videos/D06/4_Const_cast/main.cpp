/* 
Type qualifyer cast 
*/

int main(void) {

	int			a	= 42;

	int const *	b	= &a;					// Implicit demotion - OK...
	// int *		c	= b;					// Implicit demotion -> HELL NO !
	int *		d = const_cast<int *>(b);	// Explicit demotion -> Ok, I do it
}