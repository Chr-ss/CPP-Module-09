
#include "../inc/RPN.hpp"

bool	RPN::isValidDigit(const std::string &token) {
	if (token.length() > 2)
		return (false);
	for (char c : token) {
		if (!std::isdigit(static_cast<unsigned char>(c)))
			return (false);
	}
	try {
		double digit = std::stoi(token);
		if (digit > 10 || digit < 0)
			throw invalidInput();
	} catch (const std::exception &e) {
		throw invalidInput();
	}
	return (true);
}

bool miltiplyOverfowCheck(int a, int b) {
	if (a > 0 && b > 0 && a > (std::numeric_limits<int>::max() / b))
		return (true);
	if (a > 0 && b < 0 && b < (std::numeric_limits<int>::min() / a))
		return (true);
	if (a < 0 && b > 0 && a < (std::numeric_limits<int>::min() / b))
		return (true);
	if (a < 0 && b < 0 && a < (std::numeric_limits<int>::max() / b))
		return (true);
	return (false);
}

int &RPN::RPNcalculation(const std::string &input) {
	std::stringstream iss(input);
	std::string token;
	while (iss >> token) {
		// std::cout << "Token: " << token << std::endl;
		if (isValidDigit(token)) {
			stack.push(std::stoi(token));
		} else if (token == "+") {
			if (stack.size() < 2)
				throw invalidInput();
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if ((a > 0 && b > std::numeric_limits<int>::max() - a) ||
				(a < 0 && b < std::numeric_limits<int>::min() - a)) {
				throw intOverflow();
			}
			stack.push(b + a);
		}
		else if (token == "-") {
			if (stack.size() < 2)
				throw invalidInput();
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if ((a > 0 && b < std::numeric_limits<int>::min() + a) ||
				(a < 0 && b > std::numeric_limits<int>::max() + a)) {
				throw intOverflow();
			}
			stack.push(b - a);
		}
		else if (token == "*") {
			if (stack.size() < 2)
				throw invalidInput();
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (miltiplyOverfowCheck(a, b))
				throw intOverflow();
			stack.push((b * a));
			// std::cout << a * b << std::endl;
		}
		else if (token == "/") {
			if (stack.size() < 2)
				throw invalidInput();
			int a = stack.top();
			stack.pop();
			int b = stack.top();
			stack.pop();
			if (a == 0)
				throw divisionByZero();
			stack.push(b / a);
		} else
			throw invalidInput();
	}
	if (stack.size() != 1)
		throw invalidInput();
	return (stack.top());
}


const char *RPN::invalidInput::what() const throw() {
	return "Invalid input.";
}

const char *RPN::intOverflow::what() const throw() {
	return "Integer overlow.";
}

const char *RPN::divisionByZero::what() const throw() {
	return "Division by zero.";
}