#ifndef SWAP_HPP
#define SWAP_HPP

template <typename T> void swap(T& x, T& y)
{
	T tmp = x;
	x = y;
	y = tmp;
}

#endif