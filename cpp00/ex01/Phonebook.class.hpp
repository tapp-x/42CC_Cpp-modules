/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:32:52 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/08 10:39:03 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

#include "Contact.class.hpp"

class Phonebook {
private:
    Contact _contact[8];
    int index;
    void    print_line(int index);

public:
    Phonebook();
    ~Phonebook();
    void    start();
    void    exit();
    void    add();
    void    search();
    
};

#endif