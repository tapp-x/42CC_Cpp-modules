/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:55:59 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 17:22:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Harl.hpp"

int main (int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Wrong number of args" << std::endl;
		return (1);
	}
    Harl main;
    main.complain(av[1]);
	return (0);
}
