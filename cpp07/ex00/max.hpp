#ifndef MAX_HPP
#define MAX_HPP

template <typename T> T max(T& x, T& y)
{
	return (x > y) ? x : y;
}

#endif