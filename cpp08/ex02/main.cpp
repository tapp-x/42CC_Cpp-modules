#include <iostream>
#include "MutantStack.hpp"

int main() {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;

    mstack.pop();

    std::cout << "Stack size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator stop = mstack.end();

    ++it;
    --it;
    
    std::cout << "Stack elements: ";
    while (it != stop) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    return 0;
}
