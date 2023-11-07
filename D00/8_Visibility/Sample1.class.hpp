#ifndef SAMPLE1_CLASS_HPP
# define SAMPLE1_CLASS_HPP

class Sample1 {

public:

	int		publicFoo;;

	Sample1( void );
	~Sample1( void );

	void	publicBar( void ) const;

private:

	int		_privateFoo;

	void	_privateBar( void ) const;
};

#endif