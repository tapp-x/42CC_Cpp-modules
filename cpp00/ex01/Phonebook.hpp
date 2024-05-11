/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:32:52 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 18:18:52 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"

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
