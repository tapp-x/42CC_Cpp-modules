#include "PmergeMe.hpp"

int main(int ac, char** av) 
{
    if (ac < 2)
    {
        std::cerr << "Usage: " << av[0] << " <list of positive integers>\n";
        return (1);
    }
    std::vector<int> data;
    for (int i = 1; i < ac; ++i) 
    {
        int num;
        std::stringstream ss(av[i]);
        if (!(ss >> num) || num < 0) 
        {
            std::cerr << "Error: All arguments must be positive integers.\n";
            return (1);
        }
        data.push_back(num);
    }
    PmergeMe sorter(data);
    std::cout << "Before sorting:\n";
    sorter.display();

    sorter.sortWithVector();
    sorter.sortWithList();

    std::cout << "After sorting:\n";
    sorter.display();
    return (0);
}