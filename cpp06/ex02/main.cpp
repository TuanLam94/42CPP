#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>

Base* generate(void)
{
	int rand = std::rand() % 3;
	if (rand == 0) {
		std::cout << "Generating A\n"; //printing for testing purposes;
		return new A;
	}
	else if (rand == 1) {
		std::cout << "Generating B\n";
		return new B;
	}
	else {
		std::cout << "Generating C\n";
		return new C;
	}
}

void identify(Base* p)
{
	A* APtr = dynamic_cast<A*>(p);
	if (APtr) {
		std::cout << "Base is of type A\n";
		return ;
	}
	B* BPtr = dynamic_cast<B*>(p);
	if (BPtr) {
		std::cout << "Base is of type B\n";
		return ;
	}
	C* CPtr = dynamic_cast<C*>(p);
	if (CPtr) {
		std::cout << "Base is of type C\n";
		return ;
	}
	std::cout << "Could not find Base type\n";
}

void identify(Base& p)
{
	try {
		A& Aref = dynamic_cast<A&>(p);
		(void)Aref;
		std::cout << "Base is of type A\n";
		return ;
	}
	catch (const std::exception& e) {}

	try {
		B& Bref = dynamic_cast<B&>(p);
		(void)Bref;
		std::cout << "Base is of type B\n";
		return ;
	}
	catch (const std::exception& e) {}

	try {
		C& Cref = dynamic_cast<C&>(p);
		(void)Cref;
		std::cout << "Base is of type C\n";
		return ;
	}
	catch (const std::exception& e) {}

	std::cout << "Could not find Base type\n";
}

int main()
{
	std::cout << "====TESTS BEGIN====\n\n";

	Base* base = generate();
	Base* base2 = generate();
	Base* base3 = generate();
	Base* base4 = generate();

	std::cout << "\n---Identifying with pointers--\n\n";

	identify(base);
	identify(base2);
	identify(base3);
	identify(base4);

	std::cout << "\n---identifying with references---\n\n";

	identify(*base);
	identify(*base2);
	identify(*base3);
	identify(*base4);

	std::cout << "\n\n====TESTS END====" << std::endl;

	return 0;
}