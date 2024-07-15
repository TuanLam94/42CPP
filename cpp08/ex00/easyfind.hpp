#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <iterator>

template <typename T> int easyFind(T& array, int x)
{
	typename T::iterator it = std::find(array.begin(), array.end(), x);
	if (it != array.end()) 
		return std::distance(array.begin(), it);
	else
		return -1;
};

#endif