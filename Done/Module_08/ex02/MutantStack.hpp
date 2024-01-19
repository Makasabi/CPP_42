#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <algorithm>

template<typename T>
class MutantStack : public std::stack<T> {

public:
	MutantStack(void) : std::stack<T>() {return;};
	virtual ~MutantStack(void) {return;};
	MutantStack(MutantStack const & src) : std::stack<T>(src) {return;};

	MutantStack & operator=(MutantStack const & src) {
		
		std::stack<T>::operator=(src);
		return *this;
	};

	typedef typename std::stack<T>::container_type::iterator				iterator;
	typedef typename std::stack<T>::container_type::const_iterator			const_iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator		reverse_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator	const_reverse_iterator;

	iterator				begin(void) {return std::stack<T>::c.begin();}
	const_iterator			begin(void) const {return std::stack<T>::c.begin();}
	iterator				end(void) {return std::stack<T>::c.end();}
	const_iterator			end(void) const {return std::stack<T>::c.end();}
	
	reverse_iterator		rbegin(void) {return std::stack<T>::c.rbegin();}
	const_reverse_iterator 	rbegin(void) const {return std::stack<T>::c.rbegin();}
	reverse_iterator		rend(void) {return std::stack<T>::c.rend();}
	const_reverse_iterator 	rend(void) const {return std::stack<T>::c.rend();}


private:
	// nothing as the data is stored in parent class stack;

};

#endif
