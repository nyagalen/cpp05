/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:09:13 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 19:38:41 by marvin           ###   ########.fr       */
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
        std::cout << "\nLet's try to execute an unsigned form!" << std::endl;
        president.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try 
    {
        shrub.beSigned(loch);
        president.executeForm(shrub);
        pardon.beSigned(president);
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
