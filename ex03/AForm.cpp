/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:58:05 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/27 21:06:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): gradeSign(0), gradeExec(0)
{}

AForm::AForm(const std::string name, int gradeSign) : _name(name), gradeSign(gradeSign), gradeExec(0)
{
    if (gradeSign < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const std::string name, int gradeSign, int gradeExec) : _name(name), gradeSign(gradeSign), gradeExec(gradeExec)
{
    if (gradeSign < 1 || gradeExec < 1)
        throw AForm::GradeTooHighException();
    if (gradeSign > 150 || gradeExec > 150)
        throw AForm::GradeTooLowException();
}

AForm::AForm(const AForm& copyMe): _name(copyMe._name), _signed(copyMe._signed), gradeSign(copyMe.gradeSign), gradeExec(copyMe.gradeExec)
{}

AForm& AForm::operator=(const AForm& rhs)
{
    if ( this != &rhs)
        _signed = rhs.isSigned();
    return *this;
}

AForm::~AForm()
{}

std::string AForm::getName() const
{
    return this->_name;
}

bool AForm::isSigned() const
{
    return this->_signed;
}

int AForm::getGradeSign() const
{
    return this->gradeSign;
}

int AForm::getGradeExec() const
{
    return this->gradeExec;   
}

void AForm::beSigned(Bureaucrat& bureaucrat)
{
    if (bureaucrat.getGrade() > this->gradeSign)
        throw AForm::GradeTooLowException();
    _signed = true;
    std::cout << "AForm signed successfully by bureaucrat "<< bureaucrat.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& o, const AForm& rhs)
{
    o << "------AForm info------------" << std::endl;
    o << "AForm title: " << rhs.getName() << std::endl;
    o << "The AForm is signed: " << rhs.isSigned() << std::endl;
    o << "Necessary grade for signing: " << rhs.getGradeSign() << std::endl;
    o << "Necessary grade for executing: " << rhs.getGradeExec() << std::endl;
    return o;
}

