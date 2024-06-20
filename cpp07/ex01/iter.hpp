#ifndef ITER_HPP
#define ITER_HPP

template <typename T, typename F> void iter(T* array, size_t len, F fnct)
{
	for (size_t i = 0; i < len; i++) {
		fnct(array[i]);
	}
}

#endif