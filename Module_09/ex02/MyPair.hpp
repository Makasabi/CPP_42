#ifndef MYPAIR_HPP
# define MYPAIR_HPP

template<typename T>
class MyPair {

public:

	~MyPair();
	MyPair(MyPair const & src);
	MyPair(T *first, T *second);

	MyPair<T> &operator=(MyPair const & src);

	bool operator<(MyPair const & rhs) const;
	bool operator>(MyPair const & rhs) const;
	bool operator<=(MyPair const & rhs) const;
	bool operator>=(MyPair const & rhs) const;
	bool operator==(MyPair const & rhs) const;
	bool operator!=(MyPair const & rhs) const;

	T *getFirst(void) const;
	T *getSecond(void) const;

private:

	MyPair();

	T	*first;
	T	*second;
};

template<typename T>
std::ostream & operator << (std::ostream & o, MyPair<T> const & rhs);


# include "MyPair.tpp"

#endif