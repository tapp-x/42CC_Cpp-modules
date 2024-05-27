/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:05:27 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 16:05:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
public:
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm();
    
    RobotomyRequestForm(const RobotomyRequestForm& copy);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    void execute(const Bureaucrat& executor) const;

private:
    std::string _target;
};

#endif
