/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:09:13 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 23:51:10 by marvin           ###   ########.fr       */
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
    Bureaucrat mid("Just a mid guy", 45);
    Bureaucrat loch("Loch pozorny", 145);
    
    ShrubberyCreationForm shrub("forest");
    RobotomyRequestForm robotomy("Robot from StarWars");
    PresidentialPardonForm pardon("Loch pozorny");
    try
    {
        std::cout << "\n---------let's see if Zaphod Beeblebrox is good at robotomies-----" << std::endl;
        robotomy.beSigned(president);
        president.executeForm(robotomy);
        std::cout << "\n----Will a second robotomy be successful?------" << std::endl;
        mid.executeForm(robotomy);
        std::cout << "\n--------Let's try to execute an unsigned form!-------" << std::endl;
        president.executeForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        std::cout << "\n------let's see if the loch can robotomize too----" << std::endl;
        loch.executeForm(robotomy);
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
        std::cout << "\n--------------let's see if mid guy is also good at pardoning!----------"<< std::endl;
        //pardon.beSigned(president);
        mid.executeForm(pardon);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
