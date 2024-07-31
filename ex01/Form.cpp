/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:36:57 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 19:14:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("Anon form"), _signed(false), gradeSign(0), gradeExec(0)
{}

Form::Form(const std::string name, int gradeSign) : _name(name), _signed(false), gradeSign(gradeSign), gradeExec(0)
{
    if (gradeSign < 1)
        throw Form::GradeTooHighException();
    if (gradeSign > 150)
        throw Form::GradeTooLowException();
}

Form::Form(const Form& copyMe): _name(copyMe._name), _signed(copyMe._signed), gradeSign(copyMe.gradeSign), gradeExec(copyMe.gradeExec)
{}

Form& Form::operator=(const Form& rhs)
{
    if ( this != &rhs)
        _signed = rhs.isSigned();
    return *this;
}

Form::~Form()
{}

std::string Form::getName() const
{
    return this->_name;
}

bool Form::isSigned() const
{
    return this->_signed;
}

int Form::getGradeSign() const
{
    return this->gradeSign;
}

int Form::getGradeExec() const
{
    return this->gradeExec;   
}

void Form::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeSign)
        throw Form::GradeTooLowException();
    _signed = true;
    std::cout << "Form signed successfully by bureaucrat "<< CYAN <<bureaucrat.getName() <<RESET << std::endl;
}

std::ostream& operator<<(std::ostream& o, const Form& rhs)
{
    o << "------Form info------------" << std::endl;
    o << "Form title: " << rhs.getName() << std::endl;
    o << "The form is signed: " << rhs.isSigned() << std::endl;
    o << "Necessary grade for signing: " << rhs.getGradeSign() << std::endl;
    o << "Necessary grade for executing: " << rhs.getGradeExec() << std::endl;
    return o;
}

