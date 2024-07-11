/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:11:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/07/11 17:09:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"


PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& data) : _dataVector(data), _dataList(data.begin(), data.end()) {}

PmergeMe::PmergeMe(const PmergeMe& other) : _dataVector(other._dataVector), _dataList(other._dataList) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    if (this != &other) {
        _dataVector = other._dataVector;
        _dataList = other._dataList;
    }
    return (*this);
}

void PmergeMe::sortWithVector() {
    std::clock_t start = std::clock();
    fordJohnsonSortVector(_dataVector);
    std::clock_t end = std::clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time taken to sort with vector: " << elapsed << " us" << std::endl;
}

void PmergeMe::sortWithList() {
    std::clock_t start = std::clock();
    fordJohnsonSortList(_dataList);
    std::clock_t end = std::clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time taken to sort with list: " << elapsed << " us" << std::endl;
}

void PmergeMe::display() const {
    std::cout << "Vector: ";
    for (std::vector<int>::const_iterator it = _dataVector.begin(); it != _dataVector.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\nList: ";
    for (std::list<int>::const_iterator it = _dataList.begin(); it != _dataList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void PmergeMe::fordJohnsonSortVector(std::vector<int>& array) {
    mergeInsertionSortVector(array, 0, array.size() - 1);
}

void PmergeMe::fordJohnsonSortList(std::list<int>& lst) {
    mergeInsertionSortList(lst);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& array, int left, int right) {
    if (right - left + 1 <= 5)
        insertionSortVector(array, left, right);
    else
    {
        int mid = left + (right - left) / 2;
        mergeInsertionSortVector(array, left, mid);
        mergeInsertionSortVector(array, mid + 1, right);
        mergeVector(array, left, mid, right);
    }
}

void PmergeMe::mergeInsertionSortList(std::list<int>& lst) {
    if (lst.size() <= 5)
        insertionSortList(lst);
    else 
    {
        std::list<int>::iterator mid = lst.begin();
        std::advance(mid, lst.size() / 2);
        std::list<int> left(lst.begin(), mid);
        std::list<int> right(mid, lst.end());

        mergeInsertionSortList(left);
        mergeInsertionSortList(right);

        lst.clear();
        mergeList(lst, left, right);
    }
}



void PmergeMe::insertionSortVector(std::vector<int>& array, int left, int right) {
    for (int i = left + 1; i <= right; ++i)
    {
        int key = array[i];
        int j = i - 1;
        while (j >= left && array[j] > key) 
        {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = key;
    }
}

void PmergeMe::insertionSortList(std::list<int>& lst) {
    if (lst.size() < 2) 
        return;

    std::list<int>::iterator it = lst.begin();
    ++it;
    for (; it != lst.end(); ++it) 
    {
        int key = *it;
        std::list<int>::iterator j = it;
        --j;
        while (j != lst.begin() && *j > key) 
        {
            std::list<int>::iterator next = j;
            ++next;
            *next = *j;
            --j;
        }
        if (*j > key) 
        {
            std::list<int>::iterator next = j;
            ++next;
            *next = *j;
            *j = key;
        } 
        else 
        {
            std::list<int>::iterator next = j;
            ++next;
            *next = key;
        }
    }
}


void PmergeMe::mergeVector(std::vector<int>& array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = array[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) 
        {
            array[k] = L[i];
            ++i;
        } 
        else 
        {
            array[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) 
    {
        array[k] = L[i];
        ++i;
        ++k;
    }
    while (j < n2)
    {
        array[k] = R[j];
        ++j;
        ++k;
    }
}

void PmergeMe::mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right) {
    std::list<int>::iterator itLeft = left.begin();
    std::list<int>::iterator itRight = right.begin();

    while (itLeft != left.end() && itRight != right.end()) 
    {
        if (*itLeft <= *itRight) 
        {
            lst.push_back(*itLeft);
            ++itLeft;
        }
        else 
        {
            lst.push_back(*itRight);
            ++itRight;
        }
    }

    while (itLeft != left.end()) 
    {
        lst.push_back(*itLeft);
        ++itLeft;
    }

    while (itRight != right.end()) 
    {
        lst.push_back(*itRight);
        ++itRight;
    }
}
