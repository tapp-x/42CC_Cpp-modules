/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 14:57:52 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/09 15:10:40 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string *stringPTR = &str;

	std::string &stringREF = str;

	std::cout << "Memory adress for str : " << &str << std::endl;
	std::cout << "Memory adress for *stringPTR : " << &stringPTR << std::endl;
	std::cout << "Memory adress for stringREF : " << &stringREF << std::endl << std::endl;

	std::cout << "Now let's print the value behind these memory adresses" << std::endl << std::endl;

	std::cout << "Value of str : " << str << std::endl;
	std::cout << "Value of *stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value of stringREF : " << stringREF << std::endl;
}
