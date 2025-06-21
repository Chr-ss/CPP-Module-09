/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PmergeMe.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/06/21 16:06:57 by christian.r   ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <algorithm>
# include <iostream>
# include <exception>
# include <string>
# include <vector>
# include <deque>


class PmergeMe {
private:
	// size_t				_regLevel;
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
	void sortContainer(Container &container) {
		if (container.size() < 2) return;
		std::sort(container.begin(), container.end());
	}
	template <typename Container>
	void printContainer(const Container &container) const {
		for (const auto &elem : container) {
			std::cout << elem << " ";
		}
		std::cout << std::endl;
	}
};


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
