/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:13:51 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/31 16:15:35 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

#include  <iostream>

class Base {
public:
    virtual ~Base();
};

Base* generate();
void identifyPtr(Base* p);
void identifyRef(Base& p);

#endif
