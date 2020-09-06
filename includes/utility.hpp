#ifndef UTILITY_HPP
# define UTILITY_HPP

namespace ft {
template <class Key, class T>
struct pair
{
	Key			first;
	T			second;

	pair():first(Key()), second(T()){}
	pair(Key first, T second = T()):first(first), second(second){}
	pair(pair const &x):first(x.first), second(x.second){}
	pair &operator=(pair const &x){first = x.first; second = x.second; return *this;}
	bool operator==(pair const &x) const {return first == x.first;}
};

template <class Key, class T>
ft::pair<Key, T>	make_pair(Key a, T b){
	return ft::pair<Key, T>(a, b);
}

} //namespace ft

#endif
