/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/06/25 19:43:49 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <chrono>
#include <cmath>
#include <vector>
#include <list>

int F(int n)
{
    int sum = 0;
    for (int k = 1; k <= n; ++k) {
        double value = (3.0 / 4.0) * k;
        sum += static_cast<int>(ceil(log2(value)));
    }
    return sum;
}

size_t comparison = 0;
// size_t reglevel = 0;

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <list of integers to sort>" << std::endl;
		return 1;
	}
	// Print before sorting
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i)
		std::cout << argv[i] << " ";
	std::cout << std::endl;

	// START: Vector sorting
	PmergeMe<std::vector<int>> vecPmergeMe;
	auto startV = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; ++i) {
		std::string value(argv[i]);
		if (!vecPmergeMe.fillContainer(value)) {
			std::cerr << RED << BOLD << "Error: Invalid input." << RESET << std::endl;
			return (1);
		}
	}
	vecPmergeMe.sortFJMergeInsertion();
	auto endV = std::chrono::high_resolution_clock::now();
	// END: Vector sorting

	// START: List sorting
	PmergeMe<std::list<int>> listPmergeMe;
	auto startL = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; ++i) {
		std::string value(argv[i]);
		if (!listPmergeMe.fillContainer(value)) {
			std::cerr << RED << BOLD << "Error: Invalid input." << RESET << std::endl;
			return (1);
		}
	}
	listPmergeMe.sortFJMergeInsertion();
	auto endL = std::chrono::high_resolution_clock::now();
	// END: List sorting


	std::cout << "Number of comparisons: " << comparison << std::endl;
	std::cout << "Number of comparisons allowed: " << F(argc - 1) << std::endl;
	std::cout << "Number of ints to sort: " << argc - 1 << std::endl;
	comparison = 0; // Reset comparison count for deque sorting

	// Prints after sorting
	if (std::is_sorted(vecPmergeMe.getNbrs().begin(), vecPmergeMe.getNbrs().end()))
		std::cout << GREEN << BOLD;
	else
		std::cout << RED << BOLD;
	std::cout << "After: ";		printContainer(vecPmergeMe.getNbrs(), false);	std::cout << RESET << std::endl;
	std::cout << "Time to process a range of " << vecPmergeMe.getNbrs().size() << " elements with std::vector:\t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endV - startV).count() << " us" << std::endl;

	std::cout << "Number of comparisons: " << comparison << std::endl;
	std::cout << "Number of comparisons allowed: " << F(argc - 1) << std::endl;
	std::cout << "Number of ints to sort: " << argc - 1 << std::endl;
	comparison = 0; // Reset comparison count for deque sorting

	// Prints after sorting
	if (std::is_sorted(listPmergeMe.getNbrs().begin(), listPmergeMe.getNbrs().end()))
		std::cout << GREEN << BOLD;
	else
		std::cout << RED << BOLD;
	std::cout << "After: ";		printContainer(listPmergeMe.getNbrs(), false);	std::cout << RESET << std::endl;
	std::cout << "Time to process a range of " << listPmergeMe.getNbrs().size() << " elements with std::vector:\t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endL - startL).count() << " us" << std::endl;
	return (0);
}
