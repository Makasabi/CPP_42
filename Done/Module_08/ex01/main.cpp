#include "Span.hpp"

# include <time.h>
# include <list>

int main(void)
{
	//Testing for constructor/destructor, deep copy and assignment copy
{
	std::cout << _REV << _BOLD << "\tCONSTRUCTOR / DESTRUCTOR / COPY / ASSIGNMENT \n" << _END << std::endl;
	Span *test0 = new Span(2);
	try {
		test0->addNumber(rand() % 999 + 1);
		test0->addNumber(rand() % 999 + 1);
		test0->addNumber(rand() % 999 + 1);
	}
	catch (Span::FullSpanError &e)
	{
		std::cout << e.what() << std::endl;
	}
	test0->spanPrinter();

	Span test1(*test0);

	delete test0;
	test1.spanPrinter();

	Span test2(5);
	try {
		test2.addNumber(rand() % 999 + 1);
		test2.addNumber(rand() % 999 + 1);
		test2.addNumber(rand() % 999 + 1);
		test2.addNumber(rand() % 999 + 1);
		test2.addNumber(rand() % 999 + 1);
	}
	catch (Span::FullSpanError &e)
	{
		std::cout << e.what() << std::endl;
	}
	test2.spanPrinter();

	test2 = test1;
	test2.spanPrinter();
}
	// Testing longest and shorted span function and exceptions
{
	std::cout << _REV << _BOLD << "\t SHORTEST / LONGEST SPAN / EXCEPTIONS \n" << _END << std::endl;
	Span	test(6);
	try {
		test.addNumber(rand() % 999 + 1);
		test.addNumber(rand() % 999 + 1);
		test.addNumber(rand() % 999 + 1);
		test.addNumber(rand() % 999 + 1);
		test.addNumber(rand() % 999 + 1);
		test.addNumber(rand() % 999 + 1);
	}
	catch (Span::FullSpanError &e) {
		std::cout << e.what() << std::endl;
	}
	test.spanPrinter();

	try {
		std::cout << "Longest Span is: " << test.longestSpan() << std::endl;
		std::cout << "Shortest Span is: " << test.shortestSpan() << std::endl;
	}
	catch (Span::ImpossibleSpanError &e) {
		std::cout << e.what() << std::endl;
	}

	Span	test2(2);

	try {
		test2.addNumber(rand() % 999 + 1);
	}
	catch (Span::FullSpanError &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::cout << "Longest Span is: " << test2.longestSpan() << std::endl;
		std::cout << "Shortest Span is: " << test2.shortestSpan() << std::endl;
	}
	catch (Span::ImpossibleSpanError &e) {
		std::cout << e.what() << std::endl;
	}
}
	// Testing range of iterator
{
	std::cout << _REV << _BOLD << "\t RANGE ITERATOR \n" << _END << std::endl;
	srand(time(NULL));
	
	Span			test3(10);
	std::list<int>	toAdd;

	for (int i = 0; i < 12; i++)
		toAdd.push_back(rand() % 999 + 1);
	
	try {
		test3.spanFiller(toAdd.begin(), toAdd.end());
	}
	catch (Span::FullSpanError &e) {
		std::cout << e.what() << std::endl;
	}
	test3.spanPrinter();

	try {
		std::cout << "Longest Span is: " << test3.longestSpan() << std::endl;
		std::cout << "Shortest Span is: " << test3.shortestSpan() << std::endl;
	}
	catch (Span::ImpossibleSpanError &e) {
		std::cout << e.what() << std::endl;
	}
}
	return 0;
}