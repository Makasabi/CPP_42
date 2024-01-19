#ifndef HARL_CPP
# define HARL_CPP

# include <string>
# include <iostream>
# include "colors.hpp"

/////// DECLARATIONS ///////

// class Harl; 

// typedef	void	(Harl::*t_fp)(void) const;
// typedef struct	s_mssg	t_mssg;

/////// STRUCTURE ///////

// struct s_mssg
// {
// 	std::string	const	key;
// 	t_fp const			fp;
// };

/////// CLASS HARL ///////

class Harl {

public:

	Harl();
	~Harl();

	void complain( std::string level );

private:

	// static t_mssg	const	_search[];

	void debug( void ) const;
	void info( void ) const;
	void warning( void ) const;
	void error( void ) const;

};

/////// MESSAGES ///////

# define DEBUG "Do you know why I hired you? I always hire the same girl - stylish, slender, of course, worships the magazine. But so often, they turn out to be - I don't know-disappointing and, um, stupid."
# define INFO "Is there some reason that my coffee isn't here? Has she died or something?"
# define WARNING "There you are, Emily. How many times do I have to scream your name?"
# define ERROR "This… stuff ? Oh. Okay. I see. You think this has nothing to do with you. \
You go to your closet and you select… \
I don't know… that lumpy blue sweater, for instance because you're trying to tell the world \
that you take yourself too seriously to care about what you put on your back. \
But what you don't know is that that sweater is not just blue, it's not turquoise. It's not lapis. \
It's actually cerulean. And you're also blithely unaware of the fact that in 2002, Oscar de la Renta did a collection of cerulean gowns. \
And then I think it was Yves Saint Laurent… wasn't it who showed cerulean military jackets? I think we need a jacket here. \
And then cerulean quickly showed up in the collections of eight different designers. \
And then it, uh, filtered down through the department stores and then trickled on down into some tragic Casual Corner \
where you, no doubt, fished it out of some clearance bin. However, that blue represents millions of dollars and countless jobs \
and it's sort of comical how you think that you've made a choice that exempts you from the fashion industry when, in fact, \
you're wearing the sweater that was selected for you by the people in this room from a pile of stuff."

#endif