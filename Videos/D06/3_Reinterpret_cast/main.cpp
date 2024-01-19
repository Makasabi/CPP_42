/*
---> The most permisive cast of CPP
used to re-type a data flux :
typically when you don't initially know what type of data you just received.
*/

int main(void) {

	float a = 420.042f;

	void *	b	= &a;
	int * 	c	= reinterpret_cast<int *>(b);
	int & 	d	= reinterpret_cast<int &>(b);

	return 0;
}