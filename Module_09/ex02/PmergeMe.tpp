#ifndef PMERGEME_TPP
# define PMERGEME_TPP

# include "PmergeMe.hpp"

template <typename T, template <typename, class> class container>
PmergeMe<T, container>::~PmergeMe() 
{}

template <typename T, template <typename, class> class container>
PmergeMe<T, container>::PmergeMe(PmergeMe<T, container> const &src) : it(2)
{
	(void)src;
}

template <typename T, template <typename, class> class container>
PmergeMe<T, container>::PmergeMe(const container<T, std::allocator<T> > &sequence) : _it(2)
{
	this->_sequence = sequence;
}

template <typename T, template <typename, class> class container>
PmergeMe<T, container> & PmergeMe<T, container>::operator=(PmergeMe<T, container> const &src)
{
	this->_sequence = src._sequence;
}

template <typename T, template <typename, class> class container>
void PmergeMe<T, container>::SequencePrinter(std::string state)
{
	std::cout << state << ": ";
	for(typename container<T, std::allocator<T> >::iterator i = this->_sequence.begin(); i != this->_sequence.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
}

template <typename T, template <typename, class> class container>
container<T, std::allocator<T> > PmergeMe<T, container>::Compare(void)

template <typename T, template <typename, class> class container>
container<T, std::allocator<T> > PmergeMe<T, container>::fordJohnson(void)
{
	if (this->_sequence.size() / this->_it == 0) {
		for ()
	}




// création de paires
// tri des 2 éléments à l intérieur des paires (1 comparaison)
// tri des paires entre elles (ici on va utiliser notre propre fonction de manière récursive, comment trier sinon ?)
// insertion avec la suite de Jacobstal via une recherche binaire

	return _sequence;
}



// template <typename T, template <typename, class> class container>
// inline void PmergeMe<T, container>::pairSwaping(void)
// {
// 	for (typename container<T, std::allocator<T> >::iterator i = this->_sequence.begin() + 1; i != this->_sequence.end(); i += 2)
// 	{
// 		if (this->_sequence[i] < this->_sequence[i - 1])
// 			std::swap(this->_sequence[i], this->_sequence[i - 1]);
// 	}
// 	return;
// }

// template <typename T, template <typename, class> class container>
// container<T, std::allocator<T> > PmergeMe<T, container>::pairSorting(void)
// {
// 	container<MyPair<T>, std::allocator<MyPair<T> > >	pairs;

// 	if (this->_sequence.size() == 1)
// 		return this->_sequence;
	
// 	else if (this->_sequence.size() == 2)
// 	{
// 		if (this->_sequence[0] > this->_sequence[1])
// 			std::swap(this->_sequence[0], this->_sequence[1]);
// 		return this->_sequence;
// 	}
// 	this->pairSwaping();
	
// 	for(typename container<T, std::allocator<T> >::iterator i = this->_sequence.begin(); i != this->_sequence.end(); i += 2)
// 		pairs.push_back(MyPair<T>(this->_sequence[i], this->_sequence[i + 1]));

// 	PmergeMe<MyPair<T>, container>	PairedSequence(pairs);
	
// 	PairedSequence.SequencePrinter("Paired Sequence");

// 	PairedSequence.pairSorting(); 

// 	return pairs;

// }
#endif