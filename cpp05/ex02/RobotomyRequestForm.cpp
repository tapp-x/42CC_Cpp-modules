/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 16:06:15 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 16:10:37 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {
        std::cout << "Constructor RobotomyRequestForm called" << std::endl;
    }
    
RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "Destructor RobotomyRequestForm called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
    : AForm(other), _target(other._target) {
        std::cout << "Copy Constructor RobotomyRequestForm called" << std::endl;
    }

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    std::cout << "Assign operator RobotomyRequestForm called" << std::endl;
    return *this;
}


void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    if (!this->is_signed())
        throw AForm::FormNotSignedException();
    if (executor.get_grade() > this->get_exec_grade())
        throw AForm::GradeTooLowException();

    std::cout << "Try to robotomize " << _target << std::endl;
    
    if (rand() % 2 == 0)
        std::cout << _target << " has been robotomized successfully." << std::endl;
    else
        std::cout << "The robotomy on " << _target << " failed." << std::endl;
}
