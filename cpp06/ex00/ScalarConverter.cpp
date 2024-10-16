/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:08:13 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/16 19:23:30 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	(void)other;
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) { 
	(void)other;
	return *this; 
}


void ScalarConverter::convert(const std::string& literal) {
	double value = 0.0;

	if (isChar(literal))
	value = static_cast<double>(literal[0]);
	
	else if (isInt(literal)) {
		char *end;
		long stock = strtol(literal.c_str(), &end, 10);
		if (*end == '\0')
			value = static_cast<double>(stock);
		else {
			std::cout << "Invalid literal" << std::endl;
			return;
		}
	}
	
	else if (isFloat(literal)) {
		char *end;
		float stock = strtof(literal.c_str(), &end);
		if (*end == 'f' && *(end + 1) == '\0')
			value = static_cast<double>(stock);
		else {
			std::cout << "Invalid literal" << std::endl;
			return;
		}
	} 
	
	else if (isDouble(literal)) {
		char *end;
		double stock = strtod(literal.c_str(), &end);
		if (*end == '\0')
			value = stock;
		else {
			std::cout << "Invalid literal" << std::endl;
			return;
		}
	}
	
	else {
		std::cout << "Invalid literal" << std::endl;
		return;
	}

	printChar(value);
	printInt(value);
	printFloat(value);
	printDouble(value);
}

void ScalarConverter::printChar(double value) {
	if (value < 0 || value > 127 || std::isnan(value))
		std::cout << "char: impossible" << std::endl;
	else if (!std::isprint(static_cast<int>(value)))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
}

void ScalarConverter::printInt(double value) {
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max() \
		|| std::isnan(value))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void ScalarConverter::printFloat(double value) {
	float floatValue = static_cast<float>(value);
	std::cout << "float: " << floatValue;
	if (floatValue == static_cast<int>(floatValue))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: " << value;
	if (value == static_cast<int>(value))
		std::cout << ".0";
	std::cout << std::endl;
}

bool ScalarConverter::isChar(const std::string& literal) {
	if (literal.length() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0]))
		return (true);
	return (false);
}

bool ScalarConverter::isInt(const std::string& literal) {
	char* end;
	long val = strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
		return (true);
	return (false); 
}

bool ScalarConverter::isFloat(const std::string& literal) {
	if (literal.empty() || literal[literal.length() - 1] != 'f') 
		return (false);
	char* end;
	strtof(literal.c_str(), &end);
	if (*end == 'f' && *(end + 1) == '\0')
		return (true);
	return (false);
}

bool ScalarConverter::isDouble(const std::string& literal) {
	if (literal.empty()) 
		return (false);
	char* end;
	strtod(literal.c_str(), &end);
	if (*end == '\0')
		return (true);
	return (false);
}
