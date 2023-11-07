#ifndef SAMPLE1_CLASS_HPP
# define SAMPLE1_CLASS_HPP

class Sample1 {

public:

	float const		pi;
	int				qd;

	Sample1(float const pi);
	~Sample1( void );

	void	bar( void ) const;
};

#endif