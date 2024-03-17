#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::~Brain(void)
{
	std::cout << "Brain default destructor called" << std::endl;

}

Brain::Brain(Brain const & src) {

	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
	return;
}

Brain & Brain::operator=(Brain const & src) {

	for (int i = 0; i < BRAIN_SIZE; i++){
		this->_ideas[i] = src._ideas[i];
	}
	return *this;
}

std::string Brain::getIdeas(int id) const {

	return  this->_ideas[id];
}