#include "span.hpp"

int main()
{
	std::cout << "====TESTS BEGIN====\n\n";

	Span one(5);

	std::cout << "\n---printing one, should see nothing---\n";
	std::cout << one;

	one.addNumber(1);

	// std::cout << "\n---testing exceptions on shortest and longest span, should see exception---\n";

	// one.longestSpan();
	// one.shortestSpan();

	one.addNumber(3);
	one.addNumber(6);
	one.addNumber(10);
	one.addNumber(15);

	std::cout << "\n---printing one again, should see 1 3 6 10 15---\n";
	std::cout << one << std::endl;

	// std::cout << "\n\n---adding another number, should see array is full exception---\n";
	// one.addNumber(21);

	std::cout << "\n---testing longest span, should see 14---\n";

	std::cout << one.longestSpan() << std::endl;

	std::cout << "\n---test shortest span, should see 2---\n";

	std::cout << one.shortestSpan() << std::endl;

	std::cout << "\n---SUBJECT TESTS---\n";

	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;

	std::cout << "\n---testing with many values---\n";

	Span many = Span(12000);
	for (int i = 0; i < 12000; i++) {
		many.addNumber(std::rand());
	}

	std::cout << many.shortestSpan() << std::endl;
	std::cout << many.longestSpan() << std::endl;

	std::cout << "\n====TESTS END====\n";

	return 0;
}