#ifndef SAMPLE1_CLASS_HPP
# define SAMPLE1_CLASS_HPP

class Sample1 {

public:

	Sample1( void );
	~Sample1( void );

	int		getFoo( void ) const;
	void	setFoo( int v );

private:

	int		_Foo;

};

#endif