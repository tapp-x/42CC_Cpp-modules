/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 12:55:22 by tappourc          #+#    #+#             */
/*   Updated: 2024/06/02 13:04:03 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

int main() {
    // Test with int
    int intArray[] = {0, 1, 2, 3, 4};
    std::size_t intLength = sizeof(intArray) / sizeof(intArray[0]);

    std::cout << "intArray: ";
    iter(intArray, intLength, printElement);
    std::cout << std::endl;

    //Test with string
    std::string strArray[] = {"one", "two", "three", "four"};
    std::size_t strLength = sizeof(strArray) / sizeof(strArray[0]);

    std::cout << "strArray: ";
    iter(strArray, strLength, printElement);
    std::cout << std::endl;

    return 0;
}
