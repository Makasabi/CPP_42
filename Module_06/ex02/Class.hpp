#ifndef CLASS_HPP
# define CLASS_HPP

# include <exception>
# include <iostream>

class Base { public:	virtual ~Base() {};};

class A : public Base{};
class B : public Base{};
class C : public Base{};


class ErrorInstanciatingObj : public std::exception {
	public:
		virtual const char* what() const throw() { return "Error upon instanciating object";}
};

#endif
