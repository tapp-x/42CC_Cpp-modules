/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:35:33 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/21 22:06:07 by tappourc         ###   ########.fr       */
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

private:	
	std::vector<int>					_resultVector;
	std::vector<std::pair<int, int> >	_vecPairs;

	std::deque<int>						_resultDeque;
	std::deque<std::pair<int, int> >	_deqPairs;

	// Vector part	
	void	initializeVecPairs(const std::vector<int>& input);
	void	insertionSortVector(std::vector<int>& vec, int left, int right);
	void	mergeInsertionSortVector(std::vector<int>& vec, int left, int right);
	void	mergeVector(std::vector<int>& vec, int left, int mid, int right);

	// Deque part
	void	initializeDeqPairs(const std::deque<int>& input);
	void	insertionSortDeque(std::deque<int>& deq, int left, int right);
	void	mergeInsertionSortDeque(std::deque<int>& deq, int left, int right);
	void	mergeDeque(std::deque<int>& deq, int left, int mid, int right);

	// Useless here
	PmergeMe(const PmergeMe& other);
	PmergeMe& operator=(const PmergeMe& other);
};

#endif