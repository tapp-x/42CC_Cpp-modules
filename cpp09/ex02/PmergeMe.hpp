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
	void final_display() const;

private:
	std::vector<int> _resultVector;
	std::deque<int> _resultDeque;
	std::vector<s_pair> _vecPairs;
	std::deque<s_pair> _deqPairs;

	template <typename Container, typename pairContainer>
	void		initializePairs(const Container& input, pairContainer & pairs);

	template <typename Container>
	void		printContainer(const Container& container, const std::string& message) const;

	template <typename Container>
	void		printPairContainer(const Container& container, const std::string& message) const;

	template <typename Container, typename PairContainer>
	Container	sort(Container &list, PairContainer ppairs);

	template <typename Container, typename PairContainer>
	void		insertMin(PairContainer pairs, Container maximums, Container sorted, int &rightInSorted, size_t sizeToInsert);

	template <typename T>
	int			binarySearch(const T &list, int target, int left, int right);

	template <typename PairContainer>
	s_pair		findPairFromMax(const PairContainer &pairs, int max);

	template <typename PairContainer>
	s_pair		findPairFromMin(const PairContainer &pairs, int min);

	template <typename Container, typename item>
	int			findIndex(const Container &lst, item toFind);

	template <typename PairContainer>
	int			findIndexPair(const PairContainer &pairs, const s_pair &pairToFind);
};

#endif