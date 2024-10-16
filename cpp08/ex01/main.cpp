#include <iostream>
#include "Span.hpp"

int main() {
	try {
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << sp.shortestSpan() << std::endl;
		std::cout << "Longest Span: " << sp.longestSpan() << std::endl;

		Span bigSpan(10000);
		for (int i = 0; i < 10000; ++i) {
		bigSpan.addNumber(i);
		}
		std::cout << "Shortest Span (bigSpan): " << bigSpan.shortestSpan() << std::endl;
		std::cout << "Longest Span (bigSpan): " << bigSpan.longestSpan() << std::endl;

	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
