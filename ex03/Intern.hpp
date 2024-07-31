/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 02:16:05 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:04:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

#define RED "\033[31m"
#define CYAN "\033[36m"

class Intern
{
private:
    /* data */
public:
    Intern(/* args */);
    Intern(const Intern& copyMe);
    Intern &operator=(const Intern& rhs);
    ~Intern();
    AForm* newShrubbery(std::string target);
    AForm* newPardon(std::string target);
    AForm* newRobotomy(std::string target);
    AForm* makeForm(std::string type, std::string target);
};

typedef AForm *(Intern::*t_action)(std::string target); 


