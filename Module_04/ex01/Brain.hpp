#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>
# include <iostream>

# define BRAIN_SIZE 100

class Brain
{
public:
	Brain();
	Brain(Brain const & src);
	~Brain();

	Brain & operator=(Brain const & src);

	std::string getIdeas(int id) const;

private:
	std::string	_ideas[BRAIN_SIZE];

};


#endif