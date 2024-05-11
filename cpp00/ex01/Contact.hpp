/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:31:56 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/10 18:18:38 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

class Contact {

private:
    std::string _firstName;
    std::string _lastName;
    std::string _nickname;
    std::string _phoneNumber;
    std::string _darkestSecret;

public:
    Contact(void);
    ~Contact(void);
    void    init_contact();
    void    display_contact();
    std::string   get_firstname();
    std::string   get_lastname();
    std::string   get_nickname();
    std::string   get_phoneNumber();
    std::string   get_darkestSecret();
    std::string   get_infos(std::string prompt);
};

#endif
