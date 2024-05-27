/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 18:19:39 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 15:25:58 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string& name, int signGrade, int execGrade)
    : _name(name), _is_signed(false), _grade_to_sign(signGrade), _grade_to_exec(execGrade) {
    if (signGrade < 1 || execGrade < 1)
        throw GradeTooHighException();
    if (signGrade > 150 || execGrade > 150)
        throw GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed),
        _grade_to_sign(other._grade_to_sign), _grade_to_exec(other._grade_to_exec) {}

Form& Form::operator=(const Form& other) {
    if (this != &other) {
        this->_is_signed = other._is_signed;
    }
    return *this;
}

std::string Form::get_name() const { 
    return (_name); 
}
bool Form::is_signed() const {
    return (_is_signed); 
}

int Form::get_sign_grade() const {
     return (_grade_to_sign); 
}

int Form::get_exec_grade() const {
     return (_grade_to_exec); 
}

void Form::beSigned(const Bureaucrat& bureaucrat) {
    if (bureaucrat.get_grade() > _grade_to_sign)
        throw GradeTooLowException();
    _is_signed = true;
}

const char* Form::GradeTooHighException::what() const throw() {
    return "Grade too high!";
}

const char* Form::GradeTooLowException::what() const throw() {
    return "Grade too low!";
}

std::ostream& operator<<(std::ostream& out, const Form& form) {
    out << "Form " << form.get_name() << ", requires grade " << form.get_sign_grade()
        << " to sign, grade " << form.get_exec_grade() << " to execute. Signed: " << (form.is_signed() ? "Yes" : "No");
    return out;
}


