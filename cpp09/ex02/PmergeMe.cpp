/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:11:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/07/08 17:00:08 by tappourc         ###   ########.fr       */
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
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken to sort with vector: " << elapsed << " seconds" << std::endl;
}

void PmergeMe::sortWithList() {
    std::clock_t start = std::clock();
    fordJohnsonSortList(_dataList);
    std::clock_t end = std::clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    std::cout << "Time taken to sort with list: " << elapsed << " seconds" << std::endl;
}

void PmergeMe::display() const {
    std::cout << "Vector: ";
    for (const auto& num : _dataVector) {
        std::cout << num << " ";
    }
    
    std::cout << std::endl << "List: ";
    for (const auto& num : _dataList) {
        std::cout << num << " ";
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
}

void PmergeMe::mergeInsertionSortList(std::list<int>& lst) {
}

void PmergeMe::insertionSortVector(std::vector<int>& array, int left, int right) {
}

void PmergeMe::insertionSortList(std::list<int>& lst) {
}

void PmergeMe::mergeVector(std::vector<int>& array, int left, int mid, int right) {
}

void PmergeMe::mergeList(std::list<int>& lst) {
}
