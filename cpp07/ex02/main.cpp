/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:20:09 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/17 12:06:16 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include "Array.hpp"

int main() {
	try {
		Array<int> intArray(5);
		Array<int> test;

		for (unsigned int i = 0; i < intArray.get_size(); i++) {
			intArray[i] = i * 2;
		}

		std::cout << "intArray values: ";
		for (unsigned int i = 0; i < intArray.get_size(); i++) {
			std::cout << intArray[i] << " ";
		}
		std::cout << std::endl;

		Array<int> copyArray = intArray;
		std::cout << "copyArray values: ";
		for (unsigned int i = 0; i < copyArray.get_size(); i++) {
			std::cout << copyArray[i] << " ";
		}
		std::cout << std::endl;

		copyArray[0] = 42;
		std::cout << "After modification, copyArray[0]: " << copyArray[0] << std::endl;
		std::cout << "After modification, intArray[0]: " << intArray[0] << std::endl;

		try {
			std::cout << intArray[10] << std::endl;
		} catch (const std::out_of_range& e) {
			std::cerr << "Exception: " << e.what() << std::endl;
		}
	} catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}

// Official main
// #define MAX_VAL 750
// int main(int, char**)
// {
// 	Array<int> numbers(MAX_VAL);
// 	int* mirror = new int[MAX_VAL];
// 	srand(time(NULL));
// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		const int value = rand();
// 		numbers[i] = value;
// 		mirror[i] = value;
// 	}
// 	//SCOPE
// 	{
// 		Array<int> tmp = numbers;
// 		Array<int> test(tmp);
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		if (mirror[i] != numbers[i])
// 		{
// 			std::cerr << "didn't save the same value!!" << std::endl;
// 			return 1;
// 		}
// 	}
// 	try
// 	{
// 		numbers[-2] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}
// 	try
// 	{
// 		numbers[MAX_VAL] = 0;
// 	}
// 	catch(const std::exception& e)
// 	{
// 		std::cerr << e.what() << '\n';
// 	}

// 	for (int i = 0; i < MAX_VAL; i++)
// 	{
// 		numbers[i] = rand();
// 	}
// 	delete [] mirror;//
// 	return 0;
// }