#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP	

#include <iostream>
#include <deque>
#include <stack>

template < typename T, class container = std::deque<T> >
class MutantStack : public std::stack<T>
{
	public:
		using std::stack<T, container>::c;

		MutantStack() {};
		MutantStack(const MutantStack& copy) {*this = copy;}
		MutantStack& operator=(const MutantStack& rhs) {
			std::stack<T>::operator=(rhs);
			return *this;};
		~MutantStack() {};

		typedef typename container::iterator iterator;
		typedef typename container::const_iterator const_iterator;

		iterator begin() {
			return c.begin();
		}

		iterator end() {
			return c.end();
		}

		const_iterator begin() const {
			return c.begin();
		}

		const_iterator end() const {
			return c.end();
		}
};

#endif