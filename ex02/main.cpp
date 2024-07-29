/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:09:13 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/30 01:28:10 by marvin           ###   ########.fr       */
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
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
