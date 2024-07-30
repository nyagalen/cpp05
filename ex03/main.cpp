/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:09:13 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/30 15:26:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(void)
{
    Bureaucrat president("Zaphod Beeblebrox", 3);
    Bureaucrat loch("Loch pozorny", 72);

    Intern intern;

    AForm* robotomy = intern.makeForm("robotomy request", "robotomy target");
    AForm* shrub = intern.makeForm("shrubbery request", "shrub target");
    AForm* pardon = intern.makeForm("pardon request", "convicted felon");
    
    try 
    {
        shrub->beSigned(loch);
        president.executeForm(*shrub);
        robotomy->beSigned(loch);
        president.executeForm(*robotomy);
        pardon->beSigned(loch);
        president.executeForm(*pardon);
        
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    delete robotomy;
    delete shrub;
    delete pardon;
}
