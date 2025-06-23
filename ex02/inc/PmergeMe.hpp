/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/06/23 21:06:10 by crasche       ########   odam.nl         */
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

# include <algorithm>
# include <iostream>
# include <exception>
# include <string>
# include <vector>
# include <deque>
# include <cmath>

extern size_t comparison;
// extern size_t regLevel;



template <typename Container>
void sortContainer(Container &container) {
	if (container.size() < 2) return;
	std::sort(container.begin(), container.end());
}

template <typename Container>
void printContainer(const Container &container) {
	for (const auto &elem : container) {
		std::cout << elem << " ";
	}
}

#include <algorithm>
#include <vector>

// Binary insertion into sorted range [begin, begin+len)
// template<typename Container>
// void binary_insert(Container &container, int begin, int len, const int &value) {
// 	int lo = begin, hi = begin + len;
// 	while (lo < hi) {
// 		int mid = lo + (hi - lo) / 2;
// 		if (value < container[mid]) hi = mid;
// 		else lo = mid + 1;
// 	}
// 	container.insert(container.begin() + lo, value);
// }

// // Recursively sorts A[l..r) using Ford–Johnson algorithm
// template<typename Container>
// void ford_johnson(Container &container, int l, int r) {
// 	int con_size = container.size();
// 	(void)l; // Suppress unused variable warning
// 	(void)r; // Suppress unused variable warning
// 	if (con_size <= 1)
// 		return;

// 	// int pairs = con_size / 2;
// 	// Container a;
// 	// Container b;
// 	// a.reserve(pairs + (con_size % 2));
// 	// b.reserve(pairs);

// 	// // Step 1: pairwise compare
// 	// for (int i = 0; i + 1 < con_size; i += 2) {
// 	// 	int &x = container[i];
// 	// 	int &y = container[i + 1];
// 	// 	comparison++;
// 	// 	std::cout << BRIGHT_MAGENTA;
// 	// 	printContainer(a);
// 	// 	std::cout << BRIGHT_BLUE << BOLD << "   | " << y << RESET << " : ";
// 	// 	std::cout << BRIGHT_GREEN << BOLD << x << " |   " << RESET << BRIGHT_RED ;
// 	// 	printContainer(b);
// 	// 	std::cout << RESET << std::endl;
// 	// 	if (y < x)
// 	// 		std::swap(x, y);
// 	// 	a.push_back(y);
// 	// 	b.push_back(x);
// 	// }
// 	// // If odd length, one extra b value
// 	// if (con_size % 2) {
// 	// 	b.push_back(container[l + con_size - 1]);
// 	// }
// 	size_t mid = container.size() / 2;
// 	Container a(container.begin(), container.begin() + mid);
// 	Container b(container.begin() + mid, container.begin() + mid * 2);
// 	Container rest(container.begin() + mid * 2, container.end());
// 	// Step 2: recursively sort the 'a' sequence
// 	ford_johnson(a, 0, (int)a.size());

// 	// Recompose main sequence in container[l..]
// 	container[0] = a[0];

// 	// Insert remaining a-values
// 	int idx = 1;
// 	for (size_t i = 1; i < a.size(); ++i) {
// 		container[idx++] = a[i];
// 	}



// 	// // Step 3: insert b-values in Jacobsthal order
// 	int b_size = (int)b.size();
// 	Container inserted(b_size, false);

// 	// Initialize Jacobsthal numbers
// 	int JT_1 = 1;
// 	int JT_2 = 1;
// 	int JT_buffer;
// 	int JT_curr = 3;
// 	while (true) {
// 		// Calculate next Jacobsthal number
// 		JT_buffer = JT_curr;
// 		JT_curr = (JT_1 * 2) + JT_2;
// 		JT_1 = JT_2;
// 		JT_2 = JT_buffer;

// 		if (JT_curr > b_size)
// 			break;
// 		int i = JT_curr - 1;  // Index of inserted bools is 0-based
// 		if (inserted[i])
// 			continue;
// 		// We insert b[i] into current sorted prefix container[l..idx)
// 		// int prefix_len = 1 + (i >= 0 && i < (int)a.size() ? i+1 : 0);
// 		binary_insert(container, l, idx - l, b[i]);
// 		++idx;
// 		inserted[i] = true;
// 	}

// 	// Insert any remaining b’s
// 	for (int i = 0; i < b_size; ++i) {
// 		if (!inserted[i]) {
// 			binary_insert(container, l, idx - l, rest[i]);
// 			++idx;
// 		}
// 	}
// }

// // Public entry-point
// template<typename Container>
// void ford_johnson_sort(Container &c) {
// 	ford_johnson(c, 0, (int)c.size());
// }


class PmergeMe {
private:
	size_t				_regLevel = 0;
	std::vector<int>	_vnbrs;
	std::deque<int>		_dnbrs;
public:
	PmergeMe() = default;
	PmergeMe(const PmergeMe &other) = default;
	PmergeMe &operator=(const PmergeMe &other) = default;
	~PmergeMe() = default;

	// Getters
	std::vector<int> &getVector() { return _vnbrs; }
	std::deque<int> &getDeque() { return _dnbrs; }

	// Container handling templates
	template <typename Container>
	bool fillContainer(Container &container, std::string &value) {
		for (size_t i = 0; i < value.size(); ++i) {
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
			container.push_back(intNum);
		} catch (const std::invalid_argument &e) {
			std::cerr << "Invalid number: " << value << std::endl;
			return (false);
		} catch (const std::out_of_range &e) {
			std::cerr << "Number out of range: " << value << std::endl;
			return (false);
		}
		return (true);
	}

	template <typename Container>
	void sortFJMergeInsertion(Container &container) {
		_regLevel++;
		size_t size = container.size();
		// size_t group_size = 2;
		if (size < 2)
			return;
		// if (_regLevel > 1)
		size_t group_size = 1 * pow(2, _regLevel);
		std::cout << BRIGHT_MAGENTA << "group_size: " << group_size << RESET << std::endl;
		// Container splits;
		// Container rest;
		// // Split the container into groups of size group_size and fill splits with them

		Container temp(container.begin(), container.end());
		auto itTemp = container.begin() + (group_size - 1);
		while (itTemp < container.end()) {
			std::cout << BRIGHT_MAGENTA << *(itTemp - (group_size / 2)) << " : " << *itTemp << RESET << std::endl;
			comparison++;
			if (*(itTemp - (group_size / 2)) > *itTemp) {
				for (size_t i = 0; i < (group_size / 2); i++) {
					size_t tempValue = *((itTemp - (group_size / 2)) - i);
					std::cout << BRIGHT_MAGENTA << "Swapping: " << tempValue << " with " << *(itTemp - i) << RESET << std::endl;
					*((itTemp - (group_size / 2)) - i) = *(itTemp - i);
					*(itTemp - i) = tempValue;
				}
			}
			if ((itTemp + group_size) > container.end())
				break;
			itTemp = itTemp + group_size;
		}
		std::cout << BRIGHT_MAGENTA << "group_size: "<< group_size << RESET << std::endl;
		printContainer(container);
		if (group_size < (size / 2)) {
			sortFJMergeInsertion(container);
		}
		_regLevel--;
	}







	// template <typename Container>
	// void sortFJMergeInsertion1(Container &container) {
	// 	_regLevel++;
	// 	if (container.size() < 2)
	// 		return;

	// 	size_t mid = container.size() / 2;
	// 	Container left(container.begin(), container.begin() + mid);
	// 	Container right(container.begin() + mid, container.end());

	// 	sortFJMergeInsertion(left);
	// 	sortFJMergeInsertion(right);

	// 	auto itLeft = left.begin();
	// 	auto itRight = right.begin();
	// 	auto itDest = container.begin();

	// 	while (itLeft != left.end() && itRight != right.end()) {
	// 		std::cout << BRIGHT_MAGENTA;
	// 		printContainer(left);
	// 		std::cout << BRIGHT_BLUE << BOLD << "   | " << *itLeft << RESET << " : ";
	// 		std::cout << BRIGHT_GREEN << BOLD << *itRight << " |   " << RESET << BRIGHT_RED ;
	// 		printContainer(right);
	// 		std::cout << RESET << std::endl;
	// 		comparison++;
	// 		if (*itLeft <= *itRight) {
	// 			*itDest = *itLeft;
	// 			*itLeft++;
	// 		} else {
	// 			*itDest = *itRight;
	// 			*itRight++;
	// 		}
	// 		*itDest++;
	// 		// std::cout << BRIGHT_MAGENTA;
	// 		// printContainer(left);
	// 		// std::cout << BRIGHT_BLUE << BOLD << "   | " << *itLeft << RESET << " : ";
	// 		// std::cout << BRIGHT_GREEN << BOLD << *itRight << " |   " << RESET << BRIGHT_RED ;
	// 		// printContainer(right);
	// 		// std::cout << RESET << std::endl;
	// 	}
	// 	std::cout << "----------------------------------------------" << std::endl;
	// 	while (itLeft != left.end()) {
	// 		*itDest = *itLeft;
	// 		*itLeft++;
	// 		*itDest++;
	// 	}
	// 	while (itRight != right.end()) {
	// 		*itDest = *itRight;
	// 		*itRight++;
	// 		*itDest++;
	// 	}
	// 	_regLevel--;
	// }
};




