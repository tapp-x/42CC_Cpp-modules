#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span {
private:
	std::vector<int>	numbers;
	unsigned int		max_size;

public:
	Span(unsigned int n);
	~Span();

	Span(const Span& copy);
	Span & operator=(const Span& other);

	void addNumber(int number);
	void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
	int shortestSpan() const;
	int longestSpan() const;
};

#endif
