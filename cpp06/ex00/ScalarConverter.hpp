/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:08:15 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/16 19:23:56 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <limits>
#include <cmath>

class ScalarConverter {
public:
	static void convert(const std::string& literal);

private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);
	~ScalarConverter();

	static void printChar(double value);
	static void printInt(double value);
	static void printFloat(double value);
	static void printDouble(double value);

	static bool isChar(const std::string& literal);
	static bool isInt(const std::string& literal);
	static bool isFloat(const std::string& literal);
	static bool isDouble(const std::string& literal);
};

#endif
