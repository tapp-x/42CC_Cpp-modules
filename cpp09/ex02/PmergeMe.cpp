/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:11:11 by tappourc          #+#    #+#             */
/*   Updated: 2024/11/07 13:06:02 by theoappourc      ###   ########.fr       */
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
	
	// Start with the recursive sort
	mergeInsertionSortVector(_maxVec, 0, _maxVec.size() - 1);
	_resultVector = _maxVec;
	printVector(_maxVec, "After recursive sort :");

	// Here handle the first insertion :
	// insert the min corresponding to _vecMax[0]
	

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
	// printVector(vec, "enter with this vec:");
	if (right - left + 1 <= 5) {
		insertionSortVector(vec, left, right);
	} else {
		int mid = left + (right - left) / 2;
		mergeInsertionSortVector(vec, left, mid);
		mergeInsertionSortVector(vec, mid + 1, right);
	}
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

/* ************************************************************************** */
/*                                                                            */
/*                          Utils Template Functions                          */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int	PmergeMe::binarySearch(const T &list, int target, int left, int right) {
	if (left > right)
		return (0);
	int	mid = (left + right) / 2;
	if (left == right)
		return target < list[left] ? left : left + 1;
	if (target < list[mid])
		return (binarySearch(list, target, left, mid));
	return (binarySearch(list, target, mid + 1, right));
}

template <typename T>
int PmergeMe::findMinFromMax(const T& container, int maxOfPair) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (it->second == maxOfPair) {
			return (it->first);
		}
	}
	throw std::runtime_error("Max value not found");
}

template <typename T>
int PmergeMe::findMaxFromMin(const T& container, int minOfPair) {
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
		if (it->first == minOfPair) {
			return (it->second);
		}
	}
	throw std::runtime_error("Min value not found");
}

template <typename T>
int PmergeMe::findIndex(const T& container, int value) {
	typename T::const_iterator it = std::lower_bound(container.begin(), container.end(), value);
	if (it != container.end() && *it == value) {
		return std::distance(container.begin(), it);
	}
	throw std::runtime_error("Value not found");
}