/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:33:07 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 09:36:41 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>
#include <iostream>

class Harl {
  
public:
    Harl();
    ~Harl();
    void complain(std::string level);

private:
    void debug();
    void info();
    void warning();
    void error(); 
};

#endif