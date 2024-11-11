#include "PmergeMe.hpp"

int main(int ac, char** av) 
{
	if (ac < 2)
	{
		std::cerr << "Usage: " << av[0] << " <list of positive integers>" << std::endl;
		return (1);
	}

	std::vector<int> data;
	for (int i = 1; i < ac; ++i) 
	{
		int num;
		std::stringstream ss(av[i]);
		if (!(ss >> num) || num < 0) 
		{
			std::cerr << "Error: All arguments must be positive integers." << std::endl;
			return (1);
		}
		data.push_back(num);
	}

	PmergeMe sorter(data);
	sorter.printContainer(data, "Before: ");
	double timeVector = sorter.sortWithVector();
	double timeDeque = sorter.sortWithDeque();
	std::cout << "Time to process a range of " << data.size() << " elements with std::vector : " << timeVector << " us" << std::endl;
	std::cout << "Time to process a range of " << data.size() << " elements with std::deque : " << timeDeque << " us" << std::endl;
	return (0);
}