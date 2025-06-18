
#include "../inc/BitcoinExchange.hpp"


void BitcoinExchange::processData(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	std::string line;
	while (std::getline(file, line)) {
		if (line == "date,exchange_rate")
			std::getline(file, line);
		std::string date;
		double value;
		size_t delimiterPos = line.find(',');
		if (delimiterPos != std::string::npos) {
			date = line.substr(0, delimiterPos);
			try {
				value = std::stod(line.substr(delimiterPos + 1));
				data[date] = value;
			} catch (const std::invalid_argument &e) {
				std::cerr << RED << BOLD << "Invalid value in line: " << line << RESET << std::endl;
				continue;
			}
		} else {
			std::cerr << RED << BOLD << "Invalid line format: " << line << RESET << std::endl;
		}
	}
}

bool isDateFormatValid(const std::string &date)
{
	std::regex dateRegex(R"(\d{4}-\d{2}-\d{2} )");
	return (std::regex_match(date, dateRegex));
}

bool isDateLogical(const std::string &date)
{
	std::tm tm = {};
	std::istringstream ss(date);
	ss >> std::get_time(&tm, "%Y-%m-%d");
	if (ss.fail())
		return false;

	std::tm original = tm;
	mktime(&tm);
	if (tm.tm_year == original.tm_year &&
		tm.tm_mon == original.tm_mon &&
		tm.tm_mday == original.tm_mday)
		return true;
	return false;
}

void BitcoinExchange::translateExchange(const std::string &filename) {
	std::ifstream file(filename);
	if (!file.is_open())
		throw OpenFileException();
	std::string line;
	while (std::getline(file, line)) {
		if (line == "date | value")
			std::getline(file, line);
		std::string date;
		double value;
		size_t delimiterPos = line.find('|');
		if (delimiterPos != std::string::npos) {
			date = line.substr(0, delimiterPos);
			if (!isDateFormatValid(date) || !isDateLogical(date)) {
				std::cerr << RED << BOLD << "Invalid date format or logical date: " << RESET << BOLD  << date << RESET << std::endl;
				continue;
			}
			try {
				value = std::stod(line.substr(delimiterPos + 1));
				if (value < 0) {
					std::cerr << RED << BOLD << "Error: Negative value in line: " << RESET << BOLD  << line << RESET << std::endl;
					continue;
				}
				if (value > 1000) {
					std::cerr << RED << BOLD << "Error: Value exceeds maximum limit in line: " << RESET << BOLD  << line << RESET << std::endl;
					continue;
				}
				auto it = data.lower_bound(date);
				if (it->first != date && it != data.begin()) {
					--it;
				}
				if (it != data.end() && it->first <= date) {
					std::cout << date << " => " << value << " = " << value * it->second << std::endl;
				} else {
					std::cerr << RED << BOLD << "Error: Requested date before database in line: " << RESET << BOLD  << date << RESET << std::endl;
				}
			} catch (const std::invalid_argument &e) {
				std::cerr << RED << BOLD << "Error: Invalid value in line: " << RESET << BOLD  << line << RESET << std::endl;
			}
		} else {
			std::cerr << RED << BOLD << "Error: Invalid line format: " << RESET << BOLD << line << RESET << std::endl;
		}
	}
}

const char *BitcoinExchange::OpenFileException::what() const throw() {
	return ("Error: Could not open file");
}