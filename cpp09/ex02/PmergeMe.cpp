#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const std::vector<int>& data) : _resultVector(data), _resultDeque(data.begin(), data.end()) {}

PmergeMe::PmergeMe(const PmergeMe &other) {
	*this = other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other) {
	if (this != &other) {
		_resultVector = other._resultVector;
		_resultDeque = other._resultDeque;
	}
	return (*this);
}

/* ************************************************************************** */
/*                                                                            */
/*                              Display Functions                             */
/*                                                                            */
/* ************************************************************************** */

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

const size_t jacobsthal_sequence[] = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, \
										87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, \
										 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 5726623061, 11453246123};

double PmergeMe::sortWithVector() {
	std::clock_t start = std::clock();
	std::vector<int> sorted;
	std::vector<s_pair> vecPairs;
	sorted = sort(_resultVector, vecPairs);
	_resultVector = sorted;
	printContainer(sorted, "After :");
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

double PmergeMe::sortWithDeque() {
	std::clock_t start = std::clock();
	std::deque<int> sorted;
	std::vector<s_pair> deqPairs;
	sorted = sort(_resultDeque, deqPairs);
	_resultDeque = sorted;
	// printContainer(sorted, "Sorted deque:");
	std::clock_t end = std::clock();
	double elapsed = double(end - start) / CLOCKS_PER_SEC * 1000000.0;
	return (elapsed);
}

template <typename Container, typename PairContainer>
Container PmergeMe::sort(Container &list, PairContainer ppairs) {
	if (list.size() <= 1)
		return (list);
	PairContainer	pairs;
	Container		maximums;
	Container		sorted;
	//Sort max recursively
	for (typename Container::iterator it = list.begin(); it + 1 < list.end(); it += 2) {
		s_pair pair;
		pair.min = std::min(*it, *(it + 1));
		pair.max = std::max(*it, *(it + 1));
		pairs.push_back(pair);
		maximums.push_back(pair.max);
	}
	maximums = sort(maximums, ppairs);
	sorted = maximums;
	//Insert first element
	sorted.insert(sorted.begin(), findPairFromMax(pairs, maximums[0]).min);
	pairs.erase(pairs.begin() + findIndexPair(pairs, findPairFromMax(pairs, maximums[0])));
	int jacobsthalIter = 1;
	int rightInSorted = 1;
	//Insert the rest of the elements
	while (pairs.size() > 0) {
		size_t sizeToInsert = jacobsthal_sequence[jacobsthalIter];
		if (sizeToInsert > pairs.size())
			sizeToInsert = pairs.size();
		int savedSize = sizeToInsert;
		int maxIndex = rightInSorted + sizeToInsert - 1;
		while (sizeToInsert--) {
			int maxInPair = maximums[maxIndex--];
			s_pair pair = findPairFromMax(pairs, maxInPair);
			int rightIndex = findIndex(sorted, maxInPair);
			int insertionIndex = binarySearch(sorted, pair.min, 0, rightIndex);
			sorted.insert(sorted.begin() + insertionIndex, pair.min);
			pairs.erase(pairs.begin() + findIndexPair(pairs, pair));
		}
		rightInSorted += savedSize;
		jacobsthalIter++;
	}
	//Handle odd element
	handleOddElement(sorted, list);
	return (sorted);
}

template <typename Container>
void PmergeMe::handleOddElement(Container &sorted, const Container &list) {
	if (list.size() % 2 == 1) {
		int odd = list[list.size() - 1];
		int insertionIndex = binarySearch(sorted, odd, 0, sorted.size() - 1);
		sorted.insert(sorted.begin() + insertionIndex, odd);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                              Utils Functions                               */
/*                                                                            */
/* ************************************************************************** */

template <typename T>
int PmergeMe::binarySearch(const T &list, int target, int left, int right) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (list[mid] == target)
			return (mid);
		else if (list[mid] < target)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return (left);
}

template <typename PairContainer>
s_pair PmergeMe::findPairFromMax(const PairContainer &pairs, int max) {
	for (typename PairContainer::const_iterator it = pairs.begin(); it != pairs.end(); ++it) {
		if (it->max == max) {
			// std::cout << "Found pair with max " << max << " (" << it->min << ", " << it->max << ")" << std::endl;
			return (*it);
		}
	}
	s_pair nothing = {-1, -1};
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


// Here is the sort function with print statements to help you debug:
// template <typename Container, typename PairContainer>
// Container PmergeMe::sort(Container &list, PairContainer ppairs) {
// 	if (list.size() <= 1)
// 		return list;

// 	PairContainer	pairs;
// 	Container		maximums;
// 	Container		sorted;

// 	for (typename Container::iterator it = list.begin(); it + 1 < list.end(); it += 2) {
// 		s_pair pair;
// 		pair.min = std::min(*it, *(it + 1));
// 		pair.max = std::max(*it, *(it + 1));
// 		pairs.push_back(pair);
// 		maximums.push_back(pair.max);
// 	}

// 	maximums = sort(maximums, ppairs);
// 	sorted = maximums;

// 	sorted.insert(sorted.begin(), findPairFromMax(pairs, maximums[0]).min);
// 	pairs.erase(pairs.begin() + findIndexPair(pairs, findPairFromMax(pairs, maximums[0])));

// 	int jacobsthalIter = 1;
// 	int rightInSorted = 1;

// 	while (pairs.size() > 0) {
// 		size_t sizeToInsert = jacobsthal_sequence[jacobsthalIter];
// 		if (sizeToInsert > pairs.size())
// 			sizeToInsert = pairs.size();

// 		int savedSize = sizeToInsert;
// 		// std::cout << "--------------------------------------" << std::endl;
// 		// std::cout << "Chunk size: " << sizeToInsert  << " Pairs size: " << pairs.size()<< std::endl;
// 		// std::cout << "--------------------------------------" << std::endl;
// 		int maxIndex = rightInSorted + sizeToInsert - 1;
// 		// std::cout << "Max index: " << maxIndex << std::endl;
		
// 		while (sizeToInsert--) {
// 			int maxInPair = maximums[maxIndex--];
// 			// std::cout << "Max in pair: " << maxInPair << std::endl;
// 			// printPairContainer(pairs, "Pairs before find:");
// 			s_pair pair = findPairFromMax(pairs, maxInPair);
// 			// std::cout << "Pair to insert: (" << pair.min << ", " << pair.max << ")" << std::endl;
// 			// std::cout << "=====Find nb: " << maxInPair << " in sorted" <<std::endl;
// 			// printContainer(sorted, "Sorted:");
// 			int rightIndex = findIndex(sorted, maxInPair);
// 			// std::cout << "Right index: " << rightIndex << std::endl;
// 			int insertionIndex = binarySearch(sorted, pair.min, 0, rightIndex);
// 			sorted.insert(sorted.begin() + insertionIndex, pair.min);
// 			// std::cout << "Inserting " << pair.min << " at index " << insertionIndex << std::endl;
// 			// std::cout << "Sorted: " << std::endl;
// 			// for (typename Container::iterator it = sorted.begin(); it < sorted.end(); it++)
// 			// 	std::cout << *it << " ";
// 			// std::cout << std::endl;
// 			pairs.erase(pairs.begin() + findIndexPair(pairs, pair));
// 		}
// 		rightInSorted += savedSize;
// 		jacobsthalIter++;
// 	}
// 	handleOddElement(sorted, list);
// 	return (sorted);
// }