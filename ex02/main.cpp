/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:09:13 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:33:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat president("Zaphod Beeblebrox", 3);
    Bureaucrat loch("Loch pozorny", 145);
    
    ShrubberyCreationForm shrub("forest");
    RobotomyRequestForm robotomy("Robot from StarWars");
    PresidentialPardonForm pardon("Loch pozorny");
    try 
    {
        shrub.beSigned(loch);
        president.executeForm(shrub);
        president.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try 
    {
        std::cout << "\n--------------let's see if loch is also good at pardoning!----------"<< std::endl;
        pardon.beSigned(president);
        loch.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
