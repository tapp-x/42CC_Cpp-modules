#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>
#include <algorithm>
#include <ctime>

struct s_pair {
	int min;
	int max;
	int index;
};

class PmergeMe {
public:
	PmergeMe();
	~PmergeMe();
	PmergeMe(const std::vector<int>& data);
	PmergeMe(const PmergeMe &other);
	PmergeMe &operator=(const PmergeMe &other);

	double sortWithVector();
	double sortWithDeque();
	template <typename Container>
	void		printContainer(const Container& container, const std::string& message) const;

private:
	std::vector<int> _resultVector;
	std::deque<int> _resultDeque;

	template <typename Container>
	void		printPairContainer(const Container& container, const std::string& message) const;

   template <typename Container, typename PairContainer>
	Container	sort(Container &list, PairContainer ppairs);

	template <typename Container>
	void		handleOddElement(Container &sorted, const Container &list);

	template <typename T>
	int			binarySearch(const T &list, int target, int left, int right);

	template <typename PairContainer>
	s_pair		findPairFromMax(const PairContainer &pairs, int max);

	template <typename Container, typename item>
	int			findIndex(const Container &lst, item toFind);

	template <typename PairContainer>
	int			findIndexPair(const PairContainer &pairs, const s_pair &pairToFind);
};

#endif