/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RPN.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: christian.rasche <christian.rasche@stud      +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/09 14:58:12 by christian.r   #+#    #+#                 */
/*   Updated: 2025/06/19 18:06:42 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <stack>
# include <sstream>
# include <string>
# include <limits>


// template<class T, class Container = std::list<T>
// > class stack;

class RPN {
private:
	std::stack<int>	stack;
	bool isValidDigit(const std::string &token);
public:
	RPN() = default;
	~RPN() = default;
	RPN(const RPN &other) = default;
	RPN &operator=(const RPN &other) = default;

	// Member functions
	int &RPNcalculation(const std::string &input);

	// Exception Classes
	class invalidInput : public std::exception {
	public:
		const char *what() const throw();
	};
	class intOverflow : public std::exception {
	public:
		const char *what() const throw();
	};
	class divisionByZero : public std::exception {
	public:
		const char *what() const throw();
	};
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

#endif // RPN_HPP