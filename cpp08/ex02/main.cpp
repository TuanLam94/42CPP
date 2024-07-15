#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << "====TESTS BEGIN====\n\n";

	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << "\n---Printing top of the stack, should see 17---\n";
	std::cout << "top : " << mstack.top() << std::endl;

	std::cout << "\n---Popping top element and printing size, should see 1 now---\n";
	mstack.pop();
	std::cout << "size : " << mstack.size() << std::endl;


	std::cout << "\n---adding 4 new elements to the stack...---";
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "\n---now iterating through the whole stack :---\n";

	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "\n===Now doing the same with lists, should see the same output===\n";

	std::list<int> myList;

	myList.push_back(5);
	myList.push_back(17);

	std::cout << "\n---Printing top of the stack, should see 17---\n";
	std::cout << "top : " << myList.back() << std::endl;

	std::cout << "\n---Popping top element and printing size, should see 1 now---\n";
	myList.pop_back();
	std::cout << "size : " << myList.size() << std::endl;


	std::cout << "\n---adding 4 new elements to the stack...---";
	myList.push_back(3);
	myList.push_back(5);
	myList.push_back(737);
	myList.push_back(0);

	std::list<int>::iterator itl = myList.begin();
	std::list<int>::iterator itel = myList.end();

	std::cout << "\n---now iterating through the whole stack :---\n";

	++itl;
	--itl;
	while (itl != itel)
	{
		std::cout << *itl << std::endl;
		++itl;
	}

	std::cout << "\n====TESTS END====\n";

	return 0;
}