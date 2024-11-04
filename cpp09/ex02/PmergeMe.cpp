/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:11:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/11/04 12:13:34 by theoappourc      ###   ########.fr       */
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
	printVecPairs(_vecPairs);
	for (size_t i = 0; i < _vecPairs.size(); ++i) {
		if (i != _vecPairs.size() - 1)
			_minVec.push_back(std::min(_vecPairs[i].first, _vecPairs[i].second));
		_maxVec.push_back(std::max(_vecPairs[i].first, _vecPairs[i].second));
	}
	std::cout << "Now two Vecs :" << std::endl;
	printVector(_minVec, "Min of pairs :");
	printVector(_maxVec, "Max of pairs :");
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
	// printDeqPairs(_deqPairs);
	for (size_t i = 0; i < _deqPairs.size(); ++i) {
		_minDeq.push_back(std::min(_deqPairs[i].first, _deqPairs[i].second));
		_maxDeq.push_back(std::max(_deqPairs[i].first, _deqPairs[i].second));
	}
	// std::cout << "Now two Deq :" << std::endl;
	// printDeque(_minDeq, "Min of pairs :");
	// printDeque(_maxDeq, "Max of pairs :");
}

/* ************************************************************************** */
/*                                                                            */
/*                            Vector Part                                     */
/*                                                                            */
/* ************************************************************************** */

double PmergeMe::sortWithVector() {
	std::clock_t start = std::clock();
	// std::vector<int> sortedVector;
	// for (size_t i = 0; i < _vecPairs.size(); ++i) {
	// 	sortedVector.push_back(_vecPairs[i].first);
	// }
	mergeInsertionSortVector(_maxVec, 0, _maxVec.size() - 1);
	printVector(_maxVec, "After recursive sort :");
	_resultVector = _maxVec;

	// for (size_t i = 0; i < _vecPairs.size(); ++i) {
	// 	sortedVector.push_back(_vecPairs[i].second);
	// }
	// mergeInsertionSortVector(sortedVector, 0, sortedVector.size() - 1);
	// _resultVector = sortedVector;
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

void PmergeMe::mergeInsertionSortVector(std::vector<int>& vec, int left, int right) {
	printVector(vec, "enter with this vec:");
	if (right - left + 1 <= 5) {
		insertionSortVector(vec, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertionSortVector(vec, left, mid);
		mergeInsertionSortVector(vec, mid + 1, right);
		// mergeVector(vec, left, mid, right);
	}
	// printVector(vec, "After mergeInsertionSortVector:");
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

// void PmergeMe::insertionSortDeque(std::deque<int>& deq, int left, int right) {
// 	for (int i = left + 1; i <= right; ++i) {
// 		int key = deq[i];
// 		int j = i - 1;
// 		while (j >= left && deq[j] > key) {
// 			deq[j + 1] = deq[j];
// 			--j;
// 		}
// 		deq[j + 1] = key;
// 	}
// }

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

void PmergeMe::printVecPairs(const std::vector<std::pair<int, int> >& pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::printDeqPairs(const std::deque<std::pair<int, int> >& pairs) {
	for (size_t i = 0; i < pairs.size(); ++i) {
		std::cout << "(" << pairs[i].first << ", " << pairs[i].second << ") ";
	}
	std::cout << std::endl;
}

void PmergeMe::final_display() const {
	printVector(_resultVector, "After: ");
	// printDeque(_resultDeque, "Deque:");
}

template <typename Container>
int	PmergeMe::binarySearch(Container &list, int target, int left, int right) {
	if (left > right)
		return 0;

	int	mid = (left + right) / 2;

	if (left == right)
		return target < list[left] ? left : left + 1;
	if (target < list[mid])
		return binarySearch(list, target, left, mid);
	return binarySearch(list, target, mid + 1, right);
}