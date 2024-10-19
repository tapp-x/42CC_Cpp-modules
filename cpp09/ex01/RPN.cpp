#include "RPN.hpp"
#include <stack>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cstdlib>

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &copy) {
	*this = copy;
}

RPN& RPN::operator=(const RPN &other) {
	if (this != &other)
		*this = other;
	return (*this);
}

bool RPN::isOperator(const std::string& token) {
	if (token == "+" || token == "-" || token == "*" || token == "/")
		return (true);
	return (false);
}

bool RPN::isValidToken(const std::string& token) {
	if (token.size() == 1 && (token[0] >= '0' && token[0] <= '9'))
		return (true);
	else
		return (isOperator(token));
}

double RPN::performOperation(double a, double b, const std::string& op) {
	if (op == "+") 
		return (a + b);
	if (op == "-") 
		return (a - b);
	if (op == "*") 
		return (a * b);
	if (op == "/") 
	{
		if (b == 0) 
			throw std::runtime_error("Division by zero");
		return (a / b);
	}
	throw std::runtime_error("Unknown operator");
}

double RPN::evaluate(const std::string& expression) {
	std::stack<double> stack;
	std::istringstream iss(expression);
	std::string token;
	while (iss >> token) 
	{
		if (!isValidToken(token))
			throw std::runtime_error("Invalid token: " + token);
		if (isOperator(token)) 
		{
			if (stack.size() < 2)
				throw std::runtime_error("Invalid expression");
			double b = stack.top();
			stack.pop();
			double a = stack.top();
			stack.pop();
			double result = performOperation(a, b, token);
			stack.push(result);
		} 
		else
			stack.push(std::atoi(token.c_str()));
	}
	if (stack.size() != 1)
		throw std::runtime_error("Invalid expression");
	return stack.top();
}