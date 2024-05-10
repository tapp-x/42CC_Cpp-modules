/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:55:59 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:58:51 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "Harl.hpp"

int main ()
{
    Harl main;
    main.complain("debug");
    main.complain("info");
    main.complain("warning");
    main.complain("error");
    main.complain("");
}