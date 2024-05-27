/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tappourc <tappourc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:41:03 by tappourc          #+#    #+#             */
/*   Updated: 2024/05/27 15:21:09 by tappourc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {
public:
    Form(const std::string& name, int signGrade, int execGrade);
    ~Form();
    
    Form(const Form& copy);
    Form& operator=(const Form& src);

    std::string get_name() const;
    bool is_signed() const;
    int get_sign_grade() const;
    int get_exec_grade() const;

    void beSigned(const Bureaucrat& bureaucrat);

    class GradeTooHighException : public std::exception {
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
        const char* what() const throw();
    };

private:
    const std::string   _name;
    bool                _is_signed;
    const int           _grade_to_sign;
    const int           _grade_to_exec;
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
