/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: crasche <crasche@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2024/11/07 16:36:52 by crasche       #+#    #+#                 */
/*   Updated: 2025/06/18 17:45:33 by crasche       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/BitcoinExchange.hpp"

#define DATA_FILENAME "data.csv"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
		return 1;
	}
	std::cout << GREEN << "Reading Bitcoin Exchange data form file: " << RESET << BOLD  << DATA_FILENAME << RESET << std::endl;
	BitcoinExchange exchange;
	try {
		exchange.processData(DATA_FILENAME);
	} catch (const BitcoinExchange::OpenFileException &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	std::cout << BRIGHT_GREEN << "Data processed successfully." << RESET << std::endl;
	std::cout << GREEN << "Calculating Bitcoin Exchange for file: " << RESET << BOLD << argv[1] << RESET << std::endl;
	try {
		exchange.translateExchange(argv[1]);
	} catch (const BitcoinExchange::OpenFileException &e) {
		std::cerr << RED << e.what() << RESET << std::endl;
		return 1;
	}
	return 0;
}