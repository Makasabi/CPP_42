#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

# include <iostream>

class Sample {

public:

	Sample	(void);					//canonical
	Sample	(int const n);
	Sample	(Sample const & src);	//canonical
	~Sample	(void);					//canonical

	Sample &	operator=( Sample const & rhs );	//canonical

	int		getfoo(void ) const;

private:

	int		_foo;
};

std::ostream &		operator<<( std::ostream & o, Sample const & i );

#endif