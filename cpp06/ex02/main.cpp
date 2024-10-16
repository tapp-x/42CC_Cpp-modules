/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:14:07 by tappourc          #+#    #+#             */
/*   Updated: 2024/10/16 19:30:23 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main() {
	Base* base = generate();

	std::cout << "Identifying pointer: ";
	identifyPtr(base);

	std::cout << "Identifying reference: ";
	identifyRef(*base);

	delete base;

	return 0;
}
