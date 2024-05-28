/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:12:12 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 16:14:49 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
    : AForm("Presidential Pardon Form", 25, 5), _target(target) {
    std::cout << "Constructor PresidentialPardonForm called" << std::endl;
    }

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "Destructor PresidentialPardonForm called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
    : AForm(other), _target(other._target) {
    std::cout << "Copy Constructor PresidentialPardonForm called" << std::endl;
    }

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Assign operator PresidentialPardonForm called" << std::endl;
    return *this;
}


void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!this->is_signed())
        throw AForm::FormNotSignedException();
    if (executor.get_grade() > this->get_exec_grade())
        throw AForm::GradeTooLowException();

    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
