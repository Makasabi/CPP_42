#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <functional>
#include <iterator>
#include <list>
#include <type_traits>
#include <vector>

template<typename Iterator>
class group_iterator
{
private:
    Iterator _it;
    std::size_t _size;

public:
    typedef std::random_access_iterator_tag iterator_category;
    typedef Iterator iterator_type;
    typedef typename std::iterator_traits<Iterator>::value_type value_type;
    typedef typename std::iterator_traits<Iterator>::difference_type difference_type;
    typedef typename std::iterator_traits<Iterator>::pointer pointer;
    typedef typename std::iterator_traits<Iterator>::reference reference;

    group_iterator() : _it(), _size(0) {}

    group_iterator(Iterator it, std::size_t size) : _it(it), _size(size) {}

    iterator_type base() const { return _it; }

    std::size_t size() const { return _size; }

    reference operator*() const { return _it[_size - 1]; }

    pointer operator->() const { return &(operator*()); }

    group_iterator& operator++()
    {
        _it += _size;
        return *this;
    }

    group_iterator operator++(int)
    {
        auto tmp = *this;
        operator++();
        return tmp;
    }

    group_iterator& operator--()
    {
        _it -= _size;
        return *this;
    }

    group_iterator operator--(int)
    {
        auto tmp = *this;
        operator--();
        return tmp;
    }

    group_iterator& operator+=(std::size_t increment)
    {
        _it += _size * increment;
        return *this;
    }

    group_iterator& operator-=(std::size_t increment)
    {
        _it -= _size * increment;
        return *this;
    }

    decltype(_it[0]) operator[](std::size_t pos) { return _it[pos * _size + _size - 1]; }

    decltype(_it[0]) operator[](std::size_t pos) const { return _it[pos * _size + _size - 1]; }
};

template<typename Iterator1, typename Iterator2>
void iter_swap(group_iterator<Iterator1> lhs, group_iterator<Iterator2> rhs)
{
    std::swap_ranges(lhs.base(), lhs.base() + lhs.size(), rhs.base());
}

template<typename Iterator1, typename Iterator2>
bool operator==(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() == rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator!=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() != rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() < rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator<=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() <= rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>(const group_iterator<Iterator1>& lhs,
               const group_iterator<Iterator2>& rhs)
{
    return lhs.base() > rhs.base();
}

template<typename Iterator1, typename Iterator2>
bool operator>=(const group_iterator<Iterator1>& lhs,
                const group_iterator<Iterator2>& rhs)
{
    return lhs.base() >= rhs.base();
}

template<typename Iterator>
group_iterator<Iterator> operator+(group_iterator<Iterator> it, std::size_t size)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator+(std::size_t size, group_iterator<Iterator> it)
{
    return it += size;
}

template<typename Iterator>
group_iterator<Iterator> operator-(group_iterator<Iterator> it, std::size_t size)
{
    return it -= size;
}

template<typename Iterator>
typename group_iterator<Iterator>::difference_type operator-(const group_iterator<Iterator>& lhs, const group_iterator<Iterator>& rhs)
{
    return (lhs.base() - rhs.base()) / lhs.size();
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(Iterator it, std::size_t size)
{
    return group_iterator<Iterator>(it, size);
}

template<typename Iterator>
group_iterator<Iterator> make_group_iterator(group_iterator<Iterator> it, std::size_t size)
{
    return group_iterator<Iterator>(it.base(), size * it.size());
}

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort_impl(RandomAccessIterator first, RandomAccessIterator last,
                               Compare compare)
{
    static const std::uint_least64_t jacobsthal_diff[] = {
        2u, 2u, 6u, 10u, 22u, 42u, 86u, 170u, 342u, 682u, 1366u,
        2730u, 5462u, 10922u, 21846u, 43690u, 87382u, 174762u, 349526u, 699050u,
        1398102u, 2796202u, 5592406u, 11184810u, 22369622u, 44739242u, 89478486u,
        178956970u, 357913942u, 715827882u, 1431655766u, 2863311530u, 5726623062u,
        11453246122u, 22906492246u, 45812984490u, 91625968982u, 183251937962u,
        366503875926u, 733007751850u, 1466015503702u, 2932031007402u, 5864062014806u,
        11728124029610u, 23456248059222u, 46912496118442u, 93824992236886u, 187649984473770u,
        375299968947542u, 750599937895082u, 1501199875790165u, 3002399751580331u,
        6004799503160661u, 12009599006321322u, 24019198012642644u, 48038396025285288u,
        96076792050570576u, 192153584101141152u, 384307168202282304u, 768614336404564608u,
        1537228672809129216u, 3074457345618258432u, 6148914691236516864u
    };

    using std::iter_swap;

    typename std::iterator_traits<RandomAccessIterator>::difference_type size = std::distance(first, last);
    if (size < 2)
        return;

    bool has_stray = (size % 2 != 0);

    RandomAccessIterator end = has_stray ? std::prev(last) : last;
    for (RandomAccessIterator it = first; it != end; it += 2)
    {
        if (compare(it[1], it[0]))
        {
            iter_swap(it, it + 1);
        }
    }

    merge_insertion_sort_impl(
        make_group_iterator(first, 2),
        make_group_iterator(end, 2),
        compare
    );

    struct node
    {
        RandomAccessIterator it;
        typename std::list<RandomAccessIterator>::iterator next;
    };

    std::list<RandomAccessIterator> chain = {first, std::next(first)};
    std::list<node> pend;

    for (RandomAccessIterator it = first + 2; it != end; it += 2)
    {
        auto tmp = chain.insert(chain.end(), std::next(it));
        pend.push_back({it, tmp});
    }

    if (has_stray)
    {
        pend.push_back({end, chain.end()});
    }

    for (int k = 0;; ++k)
    {
        std::uint_least64_t dist = jacobsthal_diff[k];
        if (dist >= pend.size())
            break;
        auto it = pend.begin();
        std::advance(it, dist);

        while (true)
        {
            auto insertion_point = std::upper_bound(
                chain.begin(), it->next, it->it,
                [=](RandomAccessIterator lhs, RandomAccessIterator rhs) {
                    return compare(*lhs, *rhs);
                }
            );
            chain.insert(insertion_point, it->it);

            it = pend.erase(it);
            if (it == pend.begin())
                break;
            --it;
        }
    }

    while (!pend.empty())
    {
        auto it = std::prev(pend.end());
        auto insertion_point = std::upper_bound(
            chain.begin(), it->next, it->it,
            [=](RandomAccessIterator lhs, RandomAccessIterator rhs) {
                return compare(*lhs, *rhs);
            }
        );
        chain.insert(insertion_point, it->it);
        pend.pop_back();
    }

    std::vector<typename std::iterator_traits<RandomAccessIterator>::value_type> cache;
    cache.reserve(size);

    for (RandomAccessIterator& it : chain)
    {
        auto begin = it.base();
        auto end = begin + it.size();
        std::copy(begin, end, std::back_inserter(cache));
    }
    std::copy(cache.begin(), cache.end(), first.base());
}

template<typename RandomAccessIterator, typename Compare>
void merge_insertion_sort(RandomAccessIterator first, RandomAccessIterator last,
                          Compare compare)
{
    merge_insertion_sort_impl(
        make_group_iterator(first, 1),
        make_group_iterator(last, 1),
        compare
    );
}

int main()
{
    // Example usage
    std::vector<int> vec = {4, 2, 5, 1, 3};
    merge_insertion_sort(vec.begin(), vec.end());

    return 0;
}
