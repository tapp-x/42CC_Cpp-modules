#include "RPN.hpp"
#include <iostream>
#include <sstream>

int main(int argc, char* argv[]) {
	if (argc != 2) {
		std::cerr << "Wrong args number" << std::endl;
		return 1;
	}

	std::string input = argv[1];

	RPN rpn;
	try {
		double result = rpn.evaluate(input);
		std::cout << result << std::endl;
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return (1);
	}

	return (0);
}