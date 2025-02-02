/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:08:08 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/16 19:31:13 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av) 
{
	if (ac != 2) {
		std::cerr << "Enter: " << av[0] << " <value to convert>" << std::endl;
		return (1);
	}

	ScalarConverter::convert(av[1]);
	return (0);
}