/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/06/27 14:38:53 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# define RESET          "\033[0m"
# define BLACK          "\033[30m"
# define WHITE          "\033[37m"
# define BRIGHT_WHITE   "\033[97m"
# define RED            "\033[31m"
# define BRIGHT_RED     "\033[91m"
# define YELLOW         "\033[33m"
# define BRIGHT_YELLOW  "\033[93m"
# define BLUE           "\033[34m"
# define LIGHT_BLUE     "\033[38;5;123m"
# define BRIGHT_BLUE    "\033[94m"
# define MAGENTA        "\033[35m"
# define BRIGHT_MAGENTA "\033[95m"
# define CYAN           "\033[36m"
# define BRIGHT_CYAN    "\033[96m"
# define GREEN          "\033[32m"
# define BRIGHT_GREEN   "\033[92m"
# define GRAY           "\033[90m"
# define LIGHT_GRAY     "\033[37m"
# define DARK_GRAY      "\033[90m"
# define ORANGE         "\033[38;5;208m"
# define PINK           "\033[38;5;213m"
# define PURPLE         "\033[38;5;129m"
# define BOLD           "\033[1m"
# define UNDERLINE      "\033[4m"

#include <iostream>
#include <algorithm>

template <typename Container>
void sortContainer(Container &container) {
	if (container.size() < 2) return;
	std::sort(container.begin(), container.end());
}

template <typename Container>
void printContainer(const Container &container, bool limit) {
	size_t elements = 10;
	for (const auto &elem : container) {
		std::cout << elem << " ";
		if (limit && elements-- == 0) {
			std::cout << "[...]";
			return ;
		}
	}
}

template <typename T>
class PmergeMe {
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe &other) = default;
	PmergeMe &operator=(const PmergeMe &other) = default;
	~PmergeMe() = default;

	// Getters
	T &getNbrs() { return _nbrs; }

	// Sorting method
	void sortFJMergeInsertion() {
		_size = _nbrs.size();
		sortPairOfTwo();
		mergeSortDevide(0, _size - 1);
		sortForMainPend();
		insertPendElements();
	}

	// Container handling templates
	bool fillContainer(std::string &value) {
		for (size_t i = 0; i < value.size(); i++) {
			if (!std::isdigit(value[i]) && value[i] != ' ') {
				std::cerr << "Invalid character in input: \"" << value[i] << "\""<< std::endl;
				return (false);
			}
		}
		try {
			double num = std::stod(value);
			if (num < 0 || num > 2147483647) {
				std::cerr << "Number out of range: " << value << std::endl;
				return (false);
			}
			int intNum = static_cast<int>(num);
			_nbrs.push_back(intNum);
		} catch (const std::invalid_argument &e) {
			std::cerr << "Invalid number: " << value << std::endl;
			return (false);
		} catch (const std::out_of_range &e) {
			std::cerr << "Number out of range: " << value << std::endl;
			return (false);
		}
		return (true);
	}
private:
	size_t				_size;
	T					_nbrs;

	// Sorting first Pairs, 2 members per Pair only!
	void sortPairOfTwo() {
		auto	it = _nbrs.begin();
		for (size_t i = 1; i < _size; i += 2) {
			if (*it < *std::next(it))
				std::swap(*it, *std::next(it));
			it = std::next(it, 2);
		}
	}

	// Inserts the next two elements into the sorted vector
	void insertPair(typename T::iterator &itInsert, typename T::iterator &itErase) {
		itErase = std::next(itErase);
		if (itInsert == itErase)
			return ;
		int value = *itErase;
		std::size_t posIndex = std::distance(_nbrs.begin(), itErase);
		_nbrs.erase(itErase);
		itInsert = _nbrs.insert(itInsert, value);
		itErase = std::next(_nbrs.begin(), posIndex);

		if (itInsert == itErase)
			return ;
		value = *itErase;
		posIndex = std::distance(_nbrs.begin(), itErase);
		_nbrs.erase(itErase);
		itInsert = _nbrs.insert(itInsert, value);
		itErase = std::next(_nbrs.begin(), posIndex);
		itErase = std::prev(itErase);
	}

	// Mergesort insert function, merges the two parts of the devided vector
	void mergeSortInsert(size_t left, size_t mid, size_t right) {
		auto	itLeft		= std::next(_nbrs.begin(), left);
		auto	itRight		= std::next(_nbrs.begin(), mid + 1);
		size_t	startLeft	= left;
		size_t	startRight	= mid + 1;

		while (startLeft <= mid && startRight <= right) {
			if (*itLeft < *itRight) {
				itLeft = std::next(itLeft, 2);
				startLeft += 2;
			} else {
				if (startRight != right) {
					insertPair(itLeft, itRight);
				}
				itLeft = std::next(itLeft, 2);
				itRight = std::next(itRight, 2);
				startRight += 2;
			}
		}
	}

	// Revursivly divides the vector into smaller parts
	void mergeSortDevide(size_t left, size_t right) {
		if (!right || right - 1 <= left)
			return ;

		size_t mid = (right + left) / 2;
		mid = mid + (((right - left) / 2 + 1) % 2);

		mergeSortDevide(left, mid);
		mergeSortDevide(mid + 1, right);
		mergeSortInsert(left, mid, right);
	}

	// Sort for Main and Pend
	void sortForMainPend() {
		auto	itInsert	= std::next(_nbrs.begin(), 1);
		auto	itErase		= std::next(_nbrs.begin(), 2);

		for (size_t i = 2; i < _size - 1; i += 2) {
			int value = *itErase;
			size_t posIndex = std::distance(_nbrs.begin(), itErase);
			_nbrs.erase(itErase);
			itInsert = _nbrs.insert(itInsert, value);
			itErase = std::next(_nbrs.begin(), posIndex);
			itInsert = std::next(itInsert);
			itErase = std::next(itErase, 2);
		}
	}

	// Returns the Jacobsthal number for the given index
	size_t getJacobsthal(size_t indexJT) {
		if (indexJT == 0)
			return 0;
		if (indexJT == 1)
			return 1;
		return ((2 * getJacobsthal(indexJT - 2)) + getJacobsthal(indexJT - 1));
	}

	void binaryInsert(typename T::iterator itPend, size_t start, size_t end) {
		if (start >= end) {
			auto	itInsert = std::next(_nbrs.begin(), start);
			if (itPend == itInsert) {
				return;
			}
			int value = *itPend;
			_nbrs.erase(itPend);
			_nbrs.insert(itInsert, value);
			return;
		}
		size_t mid = start + (end - start) / 2;
		if (*(std::next(_nbrs.begin(), mid)) > *itPend) {
			binaryInsert(itPend, start, mid);
		} else {
			binaryInsert(itPend, mid + 1, end);
		}
	}

	// Inserts the Pend elements into the main vector
	void insertPendElements() {
		auto	itErase		= std::next(_nbrs.begin(), _size / 2);
		auto	itInsert	= _nbrs.begin();

		if (itErase == itInsert) {
			return ;
		}
		int		value		= *itErase;
		size_t	posIndex	= std::distance(_nbrs.begin(), itErase);
		_nbrs.erase(itErase);
		itInsert = _nbrs.insert(itInsert, value);
		itErase = std::next(_nbrs.begin(), posIndex);

		size_t	i			= 1;
		size_t	sizePend	= _size / 2 + _size % 2;
		for (size_t indexJT = 3; i < sizePend; indexJT++) {
			size_t	endJT = getJacobsthal(indexJT - 1);
			for (size_t j = std::min(getJacobsthal(indexJT), sizePend); j > endJT; endJT++) {
				auto	itPend = std::next(_nbrs.begin(), _size / 2);
				std::advance(itPend, j - 1);
				binaryInsert(itPend, 0, (_size / 2) + i);
				i++;
			}
		}
	}
};




