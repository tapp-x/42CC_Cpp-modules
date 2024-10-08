/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:35:33 by tappourc          #+#    #+#             */
/*   Updated: 2024/07/11 16:55:20 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <list>
#include <iostream>
#include <sstream>
#include <ctime>

class PmergeMe {
public:
    PmergeMe();
    ~PmergeMe();
    PmergeMe(const std::vector<int>& data);

    void sortWithVector();
    void sortWithList();
    void display() const;

private:

    PmergeMe(const PmergeMe& other);
    PmergeMe& operator=(const PmergeMe& other);
    
    std::vector<int> _dataVector;
    std::list<int> _dataList;

    void fordJohnsonSortVector(std::vector<int>& array);
    void mergeInsertionSortVector(std::vector<int>& array, int left, int right);
    void insertionSortVector(std::vector<int>& array, int left, int right);
    void mergeVector(std::vector<int>& array, int left, int mid, int right);

    void fordJohnsonSortList(std::list<int>& lst);
    void mergeInsertionSortList(std::list<int>& lst);
    void insertionSortList(std::list<int>& lst);
    void mergeList(std::list<int>& lst, std::list<int>& left, std::list<int>& right);
};

#endif
