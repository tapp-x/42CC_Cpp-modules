#include "Span.hpp"
#include <limits>
#include <iostream>

Span::Span(unsigned int n) : max_size(n) {
    // std::cout << "Span constructor called" << std::endl;
}

Span::~Span() {
    // std::cout << "Span destructor called" << std::endl;
}

Span::Span(const Span& other) : numbers(other.numbers), max_size(other.max_size) {
    // std::cout << "Span copy constructor called" << std::endl;

}

Span& Span::operator=(const Span& other) {
    if (this != &other) {
        this->numbers = other.numbers;
        this->max_size = other.max_size;
    }
    return *this;
}

void Span::addNumber(int number) {
    if (this->numbers.size() >= max_size) {
        throw std::overflow_error("Cannot add more numbers, Span is full");
    }
    numbers.push_back(number);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (std::distance(begin, end) > static_cast<int>(max_size - numbers.size())) {
        throw std::overflow_error("Cannot add range, Span will exceed its maximum size");
    }
    numbers.insert(numbers.end(), begin, end);
}

int Span::shortestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }

    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    int shortest = std::numeric_limits<int>::max();
    for (size_t i = 1; i < sorted.size(); ++i) {
        int span = sorted[i] - sorted[i - 1];
        if (span < shortest) {
            shortest = span;
        }
    }
    return (shortest);
}

int Span::longestSpan() const {
    if (numbers.size() < 2) {
        throw std::logic_error("Not enough numbers to find a span");
    }
    int min = *std::min_element(numbers.begin(), numbers.end());
    int max = *std::max_element(numbers.begin(), numbers.end());
    return (max - min);
}
