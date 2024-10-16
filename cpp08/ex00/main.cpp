#include "easyfind.hpp"

int main() {
	std::list<int> lst;
	for (int i = 0; i < 10; ++i) {
		lst.push_back(i);
	}
	std::cout << "List: ";
	print_all(lst);
	for (int i = 0; i < 10; ++i) {
		try {
			std::list<int>::iterator it = easyfind(lst, i);
			std::cout << "Element found in list: " << *it << std::endl;
			} catch (const NotFoundException& e) {
			std::cerr << e.what() << std::endl;
		}
	}
	try {
		std::list<int>::iterator it = easyfind(lst, 42);
		std::cout << "Element found in list: " << *it << std::endl;
		} catch (const NotFoundException& e) {
		std::cerr << e.what() << std::endl;
	}
	return 0;
}
