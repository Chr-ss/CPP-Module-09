/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/06/21 16:09:11 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <chrono>

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
	pmergeMe.sortContainer(pmergeMe.getVector());
	auto endV = std::chrono::high_resolution_clock::now();

	// Deque sorting
	auto startL = std::chrono::high_resolution_clock::now();
	for (int i = 1; i < argc; ++i) {
		std::string value(argv[i]);
		if (!pmergeMe.fillContainer(pmergeMe.getDeque(), value)) {
			std::cerr << RED << BOLD << "Error: Invalid input." << RESET << std::endl;
			return (1);
		}
	}
	pmergeMe.sortContainer(pmergeMe.getDeque());
	auto endL = std::chrono::high_resolution_clock::now();



	// Prints after sorting
	std::cout << "After: ";		pmergeMe.printContainer(pmergeMe.getVector());
	std::cout << "Time to process a range of " << pmergeMe.getVector().size() << " elements with std::vector:\t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endV - startV).count() << " us" << std::endl;
	std::cout << "Time to process a range of " << pmergeMe.getDeque().size() << " elements with std::deque:\t"
			  << std::chrono::duration_cast<std::chrono::microseconds>(endL - startL).count() << " us" << std::endl;

	return (0);
}
