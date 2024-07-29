/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:00:37 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/30 01:09:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& copyMe) : AForm(copyMe), _target(copyMe._target) {}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
    if ( this == &rhs)
     return *this;
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const
{
    if (this->isSigned() == false)
        throw AForm::NotSignedException();
    if (executor.getGrade() < 45)
        throw AForm::GradeTooLowException();
    
    static int success;
    if (success % 2 == 0)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else   
        std::cout << _target << "hasn't been robotomized" << std::endl;
    success++;
}