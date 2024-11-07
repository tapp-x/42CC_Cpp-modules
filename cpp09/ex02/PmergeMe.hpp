/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theoappourchaux <theoappourchaux@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:35:33 by tappourc          #+#    #+#             */
/*   Updated: 2024/11/07 13:06:17 by theoappourc      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const std::vector<int>& data);

	double	sortWithVector();
	double	sortWithDeque();

	// Utils
	void	final_display() const;
	void	printVector(const std::vector<int>& vec, const std::string& message) const;
	void	printDeque(const std::deque<int>& deq, const std::string& message) const;
	void	printDeqPairs(const std::deque<std::pair<int, int> >& pairs);
	void	printVecPairs(const std::vector<std::pair<int, int> >& pairs);

	template <typename T>
	static int	binarySearch(const T &list, int target, int left, int right);

	template <typename T>
	int			findIndex(const T& container, int value);

	template <typename T>
	int			findMaxFromMin(const T& container, int minVal);

	template <typename T>
	int			findMinFromMax(const T& container, int maxVal);

private:	
	std::vector<int>					_resultVector;
	std::vector<std::pair<int, int> >	_vecPairs;
	std::vector<int>					_minVec;
	std::vector<int>					_maxVec;

	std::deque<int>						_resultDeque;
	std::deque<int>						_minDeq;
	std::deque<int>						_maxDeq;
	std::deque<std::pair<int, int> >	_deqPairs;

	// Vector part	
	void	initializeVecPairs(const std::vector<int>& input);
	void	insertionSortVector(std::vector<int>& vec, int left, int right);
	void	mergeInsertionSortVector(std::vector<int>& vec, int left, int right);

	// Deque part
	void	initializeDeqPairs(const std::deque<int>& input);
	// void	insertionSortDeque(std::deque<int>& deq, int left, int right);
	// void	mergeInsertionSortDeque(std::deque<int>& deq, int left, int right);
	// void	mergeDeque(std::deque<int>& deq, int left, int mid, int right);

	// Useless here
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
};

#endif