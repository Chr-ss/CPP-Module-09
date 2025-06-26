/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/06/26 16:44:26 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

#include <chrono>
#include <cmath>
#include <vector>
#include <list>

int main(int argc, char **argv)
{
	if (argc < 2) {
		std::cerr << "Usage: " << argv[0] << " <list of integers to sort>" << std::endl;
		return 1;
	}
	// Print before sorting
	std::cout << "Before: ";
	for (int i = 1; i < argc; ++i) {
		if (i == 10) {
			std::cout << "[...] ";
			break;
		}
		std::cout << argv[i] << " ";
	}
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


	// Prints Vec after sorting
	if (std::is_sorted(vecPmergeMe.getNbrs().begin(), vecPmergeMe.getNbrs().end()))
		std::cout << GREEN << BOLD;
	else
		std::cout << RED << BOLD;
	double timeV = std::chrono::duration_cast<std::chrono::nanoseconds>(endV - startV).count();
	std::cout << "After: ";		printContainer(vecPmergeMe.getNbrs(), true);	std::cout << RESET << std::endl;
	std::cout << "Time to process a range of " << vecPmergeMe.getNbrs().size() << " elements with std::vector:\t"
			  << timeV / 10000 << " us" << std::endl;

	// Prints list after sorting
	// if (std::is_sorted(listPmergeMe.getNbrs().begin(), listPmergeMe.getNbrs().end()))
	// 	std::cout << GREEN << BOLD;
	// else
	// 	std::cout << RED << BOLD;
	// std::cout << "After: ";		printContainer(listPmergeMe.getNbrs(), true);	std::cout << RESET << std::endl;
	double timeL = std::chrono::duration_cast<std::chrono::nanoseconds>(endL - startL).count();
	std::cout << "Time to process a range of " << listPmergeMe.getNbrs().size() << " elements with std::list:\t"
			  << timeL / 10000 << " us" << std::endl;
	return (0);
}
