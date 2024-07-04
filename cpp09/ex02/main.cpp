#include <iostream>
#include <vector>
#include <sstream>

int main(int argc, char* argv[]) 
{
    if (argc < 2)
    {
        std::cerr << "Usage: " << argv[0] << " <list of positive integers>\n";
        return (1);
    }
    std::vector<int> data;
    for (int i = 1; i < argc; ++i) 
    {
        int num;
        std::stringstream ss(argv[i]);
        if (!(ss >> num) || num < 0) 
        {
            std::cerr << "Error: All arguments must be positive integers.\n";
            return (1);
        }
        data.push_back(num);
    }
    return (0);
}