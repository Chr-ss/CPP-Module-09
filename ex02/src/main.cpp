/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/06/23 16:13:19 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <chrono>

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

	// Vector sorting
	PmergeMe pmergeMe;
	auto startV = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; ++i) {
		std::string value(argv[i]);
		if (!pmergeMe.fillContainer(pmergeMe.getVector(), value)) {
			std::cerr << RED << BOLD << "Error: Invalid input." << RESET << std::endl;
			return (1);
		}
	}
	pmergeMe.sortFJMergeInsertion(pmergeMe.getVector());
	std::cout << "Number of comparisons: " << comparison << std::endl;
	comparison = 0; // Reset comparison count for deque sorting
	auto endV = std::chrono::high_resolution_clock::now();

	// Deque sorting
	auto startL = std::chrono::high_resolution_clock::now();
	// for (int i = 1; i < argc; ++i) {
	// 	std::string value(argv[i]);
	// 	if (!pmergeMe.fillContainer(pmergeMe.getDeque(), value)) {
	// 		std::cerr << RED << BOLD << "Error: Invalid input." << RESET << std::endl;
	// 		return (1);
	// 	}
	// }
	// pmergeMe.sortFJMergeInsertion(pmergeMe.getDeque());
	// std::cout << "Number of comparisons: " << comparison << std::endl;
	// comparison = 0; // Reset comparison count
	auto endL = std::chrono::high_resolution_clock::now();



	// Prints after sorting
	std::cout << "After: ";		printContainer(pmergeMe.getVector());	std::cout << std::endl;
	std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector:\t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endV - startV).count() << " us" << std::endl;
	std::cout << "Time to process a range of " << pmergeMe.getDeque().size() << " elements with std::deque:  \t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endL - startL).count() << " us" << std::endl;

	return (0);
}
