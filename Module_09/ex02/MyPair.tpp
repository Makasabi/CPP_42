#include "MyPair.hpp"

// no default constructor as it is private

//copy constructor
template <typename T>
MyPair<T>::MyPair(MyPair<T> const & src) : first(src.first), second(src.second) {}

//parametric constructor
template <typename T>
MyPair<T>::MyPair(T *first, T *second) : first(first), second(second) {}

// default destructor
template <typename T>
MyPair<T>::~MyPair() {}

// copy operator overload
template <typename T>
MyPair<T> &MyPair<T>::operator=(MyPair<T> const & src)
{
	this->first = src.first;
	this->second = src.second;
	return *this;
}

// comparison operator overload
template <typename T>
bool MyPair<T>::operator<(MyPair<T> const & rhs) const { return *this->second < *rhs.second; }

template <typename T>
bool MyPair<T>::operator>(MyPair<T> const & rhs) const { return *this->second > *rhs.second; }

template <typename T>
bool MyPair<T>::operator<=(MyPair<T> const & rhs) const { return *this->second <= *rhs.second; }

template <typename T>
bool MyPair<T>::operator>=(MyPair<T> const & rhs) const { return *this->second >= *rhs.second; }

template <typename T>
bool MyPair<T>::operator==(MyPair<T> const & rhs) const { return *this->second == *rhs.second; }

template <typename T>
bool MyPair<T>::operator!=(MyPair<T> const & rhs) const { return *this->second != *rhs.second; }

// getters
template <typename T>
T *MyPair<T>::getFirst(void) const { return this->first; }

template <typename T>
T *MyPair<T>::getSecond(void) const { return this->second; }

template <typename T>
std::ostream & operator << (std::ostream & out, MyPair<T> const & rhs)
{
	out << "[ " << *rhs.getFirst() << " ; " << *rhs.getSecond() << " ]";
	return out;
}