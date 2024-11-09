#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& data) : _resultVector(data), _resultDeque(data.begin(), data.end()) {
	initializePairs(data, _vecPairs);
	// initializePairs(std::deque<int>(data.begin(), data.end()), _deqPairs);
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_resultVector = other._resultVector;
		_resultDeque = other._resultDeque;
		_vecPairs = other._vecPairs;
		_deqPairs = other._deqPairs;
	}
	return (*this);
}


template <typename Container, typename pairContainer>
void PmergeMe::initializePairs(const Container& input, pairContainer& pairs) {
	printContainer(input, "Input:");
	pairs.clear();
	for (size_t i = 0; i < input.size(); i += 2) {
		s_pair current_pair;
		current_pair.index = i / 2;
		if (i + 1 < input.size()) {
			if (input[i] < input[i + 1]) {
				current_pair.min = input[i];
				current_pair.max = input[i + 1];
			} else {
				current_pair.min = input[i + 1];
				current_pair.max = input[i];
			}
		} else {
			current_pair.min = input[i];
			current_pair.max = input[i];
		}
		pairs.push_back(current_pair);
	}
	printPairContainer(pairs, "Pairs:");
}

/* ************************************************************************** */
/*                                                                            */
/*                              Display Functions                             */
/*                                                                            */
/* ************************************************************************** */

void PmergeMe::final_display() const {
	printContainer(_resultVector, "Vector:");
	printContainer(_resultDeque, "Deque:");
}

template <typename Container>
void PmergeMe::printContainer(const Container& container, const std::string& message) const {
	std::cout << message << " ";
	for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

template <typename Container>
void PmergeMe::printPairContainer(const Container& container, const std::string& message) const {
	std::cout << message << " " << std::endl;
	for (size_t i = 0; i < container.size(); i++) {
		std::cout << "Pair " << i << ": (" << container[i].min << ", " << container[i].max << ") ";
	}
	std::cout << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                              Sort Functions                                */
/*                                                                            */
/* ************************************************************************** */

const size_t jacobsthal_sequence[] = {2, 2, 6, 10, 22, 42, 86, 170, 342, 682, 1366, 2730, 5462, \
										10922, 21846, 43690, 87380, 174762, 349526, 699050};

double PmergeMe::sortWithVector() {
	std::clock_t start = std::clock();
	std::vector<int> sorted;
	sorted = sort(_resultVector, _vecPairs);
	_resultVector = sorted;
	printContainer(sorted, "Sorted vector:");
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

template <typename Container, typename PairContainer>
Container PmergeMe::sort(Container &list, PairContainer ppairs) {
	if (list.size() <= 1)
		return list;

	PairContainer	pairs;
	Container		maximums;
	Container		sorted;

	// std::cout << "Initial list: ";
	// for (typename Container::iterator it = list.begin(); it != list.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	// 1. Create pairs of elements and store the maximum of each pair.
	for (typename Container::iterator it = list.begin(); it + 1 < list.end(); it += 2) {
		s_pair pair;
		pair.min = std::min(*it, *(it + 1));
		pair.max = std::max(*it, *(it + 1));
		pairs.push_back(pair);
		maximums.push_back(pair.max);
	}

	// std::cout << "Pairs: ";
	// for (typename PairContainer::iterator it = pairs.begin(); it != pairs.end(); ++it) {
	// 	std::cout << "(" << it->min << ", " << it->max << ") ";
	// }
	// std::cout << std::endl;

	// std::cout << "Maximums before sorting: ";
	// for (typename Container::iterator it = maximums.begin(); it != maximums.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	maximums = sort(maximums, ppairs);
	sorted = maximums;

	// std::cout << "Sorted maximums: ";
	// for (typename Container::iterator it = sorted.begin(); it != sorted.end(); ++it) {
	// 	std::cout << *it << " ";
	// }
	// std::cout << std::endl;

	sorted.insert(sorted.begin(), findPairFromMax(pairs, maximums[0]).min);
	pairs.erase(pairs.begin() + findIndexPair(pairs, findPairFromMax(pairs, maximums[0])));

	int jacobsthalIter = 1;
	int rightInSorted = 1;
	while (pairs.size() > 0) {
		size_t sizeToInsert = jacobsthal_sequence[jacobsthalIter];
		if (sizeToInsert > pairs.size())
			sizeToInsert = pairs.size();

		int savedSize = sizeToInsert;
		std::cout << "--------------------------------------" << std::endl;
		std::cout << "Chunk size: " << sizeToInsert  << " Pairs size: " << pairs.size()<< std::endl;
		std::cout << "--------------------------------------" << std::endl;
		int maxIndex = rightInSorted + sizeToInsert - 1;
		// std::cout << "Max index: " << maxIndex << std::endl;
		
		while (sizeToInsert--) {
			int maxInPair = maximums[maxIndex--];
			// std::cout << "Max in pair: " << maxInPair << std::endl;
			printPairContainer(pairs, "Pairs before find:");
			s_pair pair = findPairFromMax(pairs, maxInPair);
			std::cout << "Pair to insert: (" << pair.min << ", " << pair.max << ")" << std::endl;
			std::cout << "=====Find nb: " << maxInPair << " in sorted" <<std::endl;
			printContainer(sorted, "Sorted:");
			int rightIndex = findIndex(sorted, maxInPair);
			std::cout << "Right index: " << rightIndex << std::endl;
			int insertionIndex = binarySearch(sorted, pair.min, 0, rightIndex);
			sorted.insert(sorted.begin() + insertionIndex, pair.min);
			std::cout << "Inserting " << pair.min << " at index " << insertionIndex << std::endl;
			std::cout << "Sorted: " << std::endl;
			for (typename Container::iterator it = sorted.begin(); it < sorted.end(); it++)
				std::cout << *it << " ";
			std::cout << std::endl;
			pairs.erase(pairs.begin() + findIndexPair(pairs, pair));
		}
		rightInSorted += savedSize;
		jacobsthalIter++;
	}
	if (list.size() % 2 == 1) {
		int	odd = list[list.size() - 1];
		int	insertionIndex = binarySearch(sorted, odd, 0, sorted.size() - 1);
		sorted.insert(sorted.begin() + insertionIndex, odd);
	}	
	return (sorted);
}

/* ************************************************************************** */
/*                                                                            */
/*                              Utils Functions                               */
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

template <typename PairContainer>
s_pair PmergeMe::findPairFromMax(const PairContainer &pairs, int max) {
	for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->max == max) {
			// std::cout << "Found pair with max " << max << " (" << it->min << ", " << it->max << ")" << std::endl;
			return (*it);
		}
	}
	s_pair nothing = {-1, -1, -1};
	return (nothing);
}

template <typename PairContainer>
s_pair PmergeMe::findPairFromMin(const PairContainer &pairs, int min) {
	for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->min == min) {
			// std::cout << "Found pair with min " << min << " (" << it->min << ", " << it->max << ")" << std::endl;
			return (*it);
		}
	}
	s_pair nothing = {-1, -1, -1};
	return (nothing);
}

template <typename Container, typename item>
int PmergeMe::findIndex(const Container &lst, item toFind) {
	for (size_t i = 0; i < lst.size(); i++) {
		if (lst[i] == toFind)
			return (i);
	}
	return (-1);
}

template <typename PairContainer>
int PmergeMe::findIndexPair(const PairContainer &pairs, const s_pair &pairToFind) {
	for (size_t i = 0; i < pairs.size(); i++) {
		if (pairs[i].min == pairToFind.min && pairs[i].max == pairToFind.max)
			return (i);
	}
	return (-1);
}