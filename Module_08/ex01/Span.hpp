#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <algorithm>
# include <iterator>
# include <iostream>

# include "colors.hpp"

class Span {

public:
	Span(unsigned int n);
	~Span(void);
	Span(Span const &src);

	Span & operator=(Span const &src);

	unsigned int		getSize(void) const;

	void				addNumber(const int & n);

	unsigned int		shortestSpan(void);
	unsigned int		longestSpan(void);

	template<typename InputIterator>
	void spanFiller(InputIterator first, InputIterator last)
	{
		for (;first != last; ++first)
		{
			try {
				this->addNumber(*first);
			}
			catch (Span::FullSpanError &e){
				std::cout << e.what() << std::endl;
			}
		}
	}

	void				spanPrinter(void);

	class FullSpanError : public std::exception {
		public:
		virtual const char* what() const throw() {return _CORAL "Span is already full!" _END;}
	};

	class ImpossibleSpanError : public std::exception {
		public:
		virtual const char* what() const throw() {return _CORAL "No Span can be computed" _END;}
	};

private:

	unsigned int		_size;
	std::vector<int>	_span;

	Span(void);
};

#endif
