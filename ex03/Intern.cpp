/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:15:16 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:00:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern& copyMe)
{
    *this = copyMe;
}

Intern& Intern::operator=(const Intern& rhs)
{
    if (this == &rhs)
        return *this;
    return *this;
}

Intern::~Intern() {}

AForm* Intern::newShrubbery(std::string target)
{
    return new ShrubberyCreationForm(target);
}

AForm* Intern::newPardon(std::string target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::newRobotomy(std::string target)
{
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(std::string type, std::string target)
{
    AForm* form = NULL;
    
    std::string options[] = {"robotomy request", "shrubbery request", "pardon request"};
    t_action forms[] = {&Intern::newShrubbery, &Intern::newRobotomy, &Intern::newPardon};
    for (int i = 0; i < 3; i++)
    {
        if (type == options[i])
        {
            form = (this->*forms[i])(target);
            break;
        }   
    }
    if (form == NULL)
        std::cerr << RED"Form doesn't exist" << std::endl;
    return form;
}
