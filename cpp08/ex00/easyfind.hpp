#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <iterator>
#include <iostream>
#include <list>

class NotFoundException : public std::exception {
public:
	const char* what() const throw() {
		return ("Element not found");
	}
};

template <typename T>
typename T::iterator easyfind(T& cont, int value) {
	typename T::iterator iter = std::find(cont.begin(), cont.end(), value);
	if (iter == cont.end())
		throw NotFoundException();
	return (iter);
}

template <typename T>
void	print_all(T& cont) {
	for (typename T::iterator it = cont.begin(); it != cont.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

#endif
