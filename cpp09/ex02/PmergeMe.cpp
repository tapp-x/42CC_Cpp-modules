/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:11:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/21 22:03:44 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& data) : _resultVector(data), _resultDeque(data.begin(), data.end()) {
	initializeVecPairs(data);
	initializeDeqPairs(std::deque<int>(data.begin(), data.end()));
}

PmergeMe::PmergeMe(const PmergeMe& other) {
	_resultVector = other._resultVector;
	_vecPairs = other._vecPairs;
	_resultDeque = other._resultDeque;
	_deqPairs = other._deqPairs;
}

void PmergeMe::initializeVecPairs(const std::vector<int>& input) {
	_vecPairs.clear();
	for (size_t i = 0; i < input.size(); i += 2) {
		if (i + 1 < input.size()) {
			if (input[i] < input[i + 1]) {
				_vecPairs.push_back(std::make_pair(input[i], input[i + 1]));
			} else {
				_vecPairs.push_back(std::make_pair(input[i + 1], input[i]));
			}
		} else {
			_vecPairs.push_back(std::make_pair(input[i], input[i])); // Si le nombre d'éléments est impair
		}
	}
	// printVector(input, "Vector:");
}

void PmergeMe::initializeDeqPairs(const std::deque<int>& input) {
	_deqPairs.clear();
	for (size_t i = 0; i < input.size(); i += 2) {
		if (i + 1 < input.size()) {
			if (input[i] < input[i + 1]) {
				_deqPairs.push_back(std::make_pair(input[i], input[i + 1]));
			} else {
				_deqPairs.push_back(std::make_pair(input[i + 1], input[i]));
			}
		} else {
			_deqPairs.push_back(std::make_pair(input[i], input[i])); // Si le nombre d'éléments est impair
		}
	}
	// printDeque(input, "Deque:");
}

/* ************************************************************************** */
/*                                                                            */
/*                            Vector Part                                     */
/*                                                                            */
/* ************************************************************************** */

double PmergeMe::sortWithVector() {
	std::clock_t start = std::clock();
	std::vector<int> sortedVector;
	for (size_t i = 0; i < _vecPairs.size(); ++i) {
		sortedVector.push_back(_vecPairs[i].first);
	}
	mergeInsertionSortVector(sortedVector, 0, sortedVector.size() - 1);
	for (size_t i = 0; i < _vecPairs.size(); ++i) {
		sortedVector.push_back(_vecPairs[i].second);
	}
	mergeInsertionSortVector(sortedVector, 0, sortedVector.size() - 1);
	_resultVector = sortedVector;
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& vec, int left, int right) {
	if (right - left + 1 <= 5) {
		insertionSortVector(vec, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertionSortVector(vec, left, mid);
		mergeInsertionSortVector(vec, mid + 1, right);
		mergeVector(vec, left, mid, right);
	}
	// printVector(vec, "After mergeInsertionSortVector:");
}

void PmergeMe::mergeVector(std::vector<int>& vec, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::vector<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = vec[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = vec[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			vec[k] = L[i];
			++i;
		} else {
			vec[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		vec[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		vec[k] = R[j];
		++j;
		++k;
	}
	// printVector(vec, "After mergeVector:");
}

/* ************************************************************************** */
/*                                                                            */
/*                            Deque Part                                      */
/*                                                                            */
/* ************************************************************************** */

double PmergeMe::sortWithDeque() {
	std::clock_t start = std::clock();
	std::deque<int> sortedDeque;
	for (size_t i = 0; i < _deqPairs.size(); ++i) {
		sortedDeque.push_back(_deqPairs[i].first);
	}
	mergeInsertionSortDeque(sortedDeque, 0, sortedDeque.size() - 1);
	for (size_t i = 0; i < _deqPairs.size(); ++i) {
		sortedDeque.push_back(_deqPairs[i].second);
	}
	mergeInsertionSortDeque(sortedDeque, 0, sortedDeque.size() - 1);
	_resultDeque = sortedDeque;
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

void PmergeMe::mergeInsertionSortDeque(std::deque<int>& deq, int left, int right) {
	if (right - left + 1 <= 5) {
		insertionSortDeque(deq, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertionSortDeque(deq, left, mid);
		mergeInsertionSortDeque(deq, mid + 1, right);
		mergeDeque(deq, left, mid, right);
	}
	// printDeque(deq, "After mergeInsertionSortDeque:");
}

void PmergeMe::mergeDeque(std::deque<int>& deq, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	std::deque<int> L(n1), R(n2);

	for (int i = 0; i < n1; ++i)
		L[i] = deq[left + i];
	for (int j = 0; j < n2; ++j)
		R[j] = deq[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			deq[k] = L[i];
			++i;
		} else {
			deq[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		deq[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		deq[k] = R[j];
		++j;
		++k;
	}
	// printDeque(deq, "After mergeDeque:");
}

/* ************************************************************************** */
/*                                                                            */
/*                            Insertion Sort Functions                        */
/*                                                                            */
/* ************************************************************************** */

void PmergeMe::insertionSortVector(std::vector<int>& array, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = array[i];
		int j = i - 1;
		while (j >= left && array[j] > key) {
			array[j + 1] = array[j];
			--j;
		}
		array[j + 1] = key;
	}
}

void PmergeMe::insertionSortDeque(std::deque<int>& deq, int left, int right) {
	for (int i = left + 1; i <= right; ++i) {
		int key = deq[i];
		int j = i - 1;
		while (j >= left && deq[j] > key) {
			deq[j + 1] = deq[j];
			--j;
		}
		deq[j + 1] = key;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                            Print Functions                                 */
/*                                                                            */
/* ************************************************************************** */

void PmergeMe::printVector(const std::vector<int>& vec, const std::string& message) const {
	std::cout << message << " ";
	for (std::vector<int>::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeque(const std::deque<int>& deq, const std::string& message) const {
	std::cout << message << " ";
	for (std::deque<int>::const_iterator it = deq.begin(); it != deq.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void PmergeMe::final_display() const {
	printVector(_resultVector, "After: ");
	// printDeque(_resultDeque, "Deque:");
}