#include "MutantStack.hpp"
#include "colors.hpp"
#include <iostream>
#include <list>
#include <string>

int main()
{
	std::cout << _REV << "\nSTACK\n" << _END << std::endl;
	{

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "Stack Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Stack Top: " << mstack.top() << std::endl;
	std::cout << "Stack Size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Stack order: " << std::endl;
	while (it != ite)
	{
		std::cout << "-> " << *it << std::endl;
		++it;
	}
	std::stack<int> test(mstack);

	MutantStack<int> s(mstack);

	MutantStack<int>::reverse_iterator rit = s.rbegin();
	MutantStack<int>::reverse_iterator rite = s.rend();

	std::cout << "Stack reverse order: " << std::endl;
	while (rit != rite)
	{
		std::cout << "-> " << *rit << std::endl;
		++rit;
	}

	}

	std::cout << _REV << "\nLIST\n" << _END << std::endl;
	{
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);

	std::cout << "List Top: " << mstack.back() << std::endl;
	mstack.pop_back();
	std::cout << "List Top: " << mstack.back() << std::endl;
	std::cout << "List size: " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "List order: " << std::endl;
	while (it != ite)
	{
		std::cout << "-> " << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);


	std::list<int>::reverse_iterator rit = s.rbegin();
	std::list<int>::reverse_iterator rite = s.rend();

	std::cout << "Stack reverse order: " << std::endl;
	while (rit != rite)
	{
		std::cout << "-> " << *rit << std::endl;
		++rit;
	}
	}
	// std::cout << _REV << "\nINITIIALISE STACK WITH UNDERLYING LIST\n" << _END << std::endl;
	{
	// // Instantiate a stack using std::list as the underlying container
	// std::stack <int, std::list <int> > myStack;

	// // Push elements onto the stack
	// myStack.push(1);
	// myStack.push(2);
	// myStack.push(3);

	// // Pop and print elements from the stack
	// while (!myStack.empty()) {
	// 	std::cout << myStack.top() << " ";
	// 	myStack.pop();
	// }
	}
	return 0;
}