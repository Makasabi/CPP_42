#include "Span.hpp"

Span::Span(unsigned int n) : _size(n)
{
	std::cout << _GREYER << _ITALIC << "Parametric constructor called with size = " << n << _END << std::endl;
	return;
}

Span::~Span(void)
{
	std::cout << _GREYER << _ITALIC << "Destructor called" << _END << std::endl;
}

Span::Span(Span const & src)
{
	std::cout << _GREYER << _ITALIC << "Copy constructor called with size = " << src._size << _END << std::endl;
	this->_size = src._size;
	this->_span = src._span;
}

Span & Span::operator=(Span const & src)
{
	this->_size = src.getSize();
	this->_span.assign(src._span.begin(), src._span.end());
	return *this;
}

unsigned int	Span::getSize(void) const
{
	return this->_size;
}

void Span::addNumber(const int & n)
{
	if (this->_span.size() >= this->_size)
		throw Span::FullSpanError();
	_span.push_back(n);
}

void Span::spanPrinter(void)
{
	for(std::vector<int>::iterator i = this->_span.begin(); i != this->_span.end(); ++i)
		std::cout << *i << std::endl;
}

unsigned int Span::shortestSpan(void)
{
	if (this->_span.size() < 2)
		throw ImpossibleSpanError();
	std::vector<int>	copy = this->_span;
	std::sort(copy.begin(), copy.end());
	std::vector<int>::iterator i = copy.begin();
	unsigned int shortest = *(i + 1) - *i;
	for (++i; *i != copy.back(); i++)
		shortest = std::min(shortest, static_cast<unsigned int>(*(i + 1) - *i));
	return shortest;
}

unsigned int Span::longestSpan(void)
{
	if (this->_span.size() < 2)
		throw ImpossibleSpanError();
	std::vector<int>	copy = this->_span;
	std::sort(copy.begin(), copy.end());
	return (copy.back() - copy.front());
}

