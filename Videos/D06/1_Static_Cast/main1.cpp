int main(void) {

	int a = 42;							// Reference value
	
	double b 	= a; 					// Implicit promotion;
	int c 		= b;					// Implicit demotion --> HELL NO!
	int d 		= static_cast<int>(b);	// Explicit demotion --> Ok, i do it.

	return 0;
}