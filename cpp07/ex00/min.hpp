#ifndef MIN_HPP
#define MIN_HPP

template <typename T> T min(T& x, T& y)
{
	return (x < y) ? x : y;
}

#endif