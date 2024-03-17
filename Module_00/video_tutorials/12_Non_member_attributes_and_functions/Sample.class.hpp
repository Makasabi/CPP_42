#ifndef SAMPLE_CLASS_HPP
# define SAMPLE_CLASS_HPP

class Sample {

public:

	Sample( void );
	~Sample( void );

	static int	getNbInst( void );

private:

	static int	_nbInst;
};


#endif