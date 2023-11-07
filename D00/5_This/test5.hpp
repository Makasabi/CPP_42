#ifndef TEST5_HPP
# define TEST5_HPP

#include <string>

class	test5 {

public: 

// VARIABLE //
	int			foo;
	std::string	color;

// CONSTRUCTOR & DESTRUCTOR //
	test5(void);
	~test5(void);

// FUNCTION //
	void	bar(void);
	void	paint(std::string color);

};

#endif