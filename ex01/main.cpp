/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:35:29 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 23:25:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
    std::cout << "-----Creating first bureaucrat--------" << std::endl;
    Bureaucrat bur1("bur1", 100);
    std::cout << "------Creating second bureaucrat------" << std::endl;
    Bureaucrat bur2("bur2", 150);
    std::cout << "\nCreating a form" << std::endl;
    Form form("form", 130);
    try
    {
        std::cout << "----let's try to create an invalid form------" << std::endl;
        Form badForm("Badform", 151);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << "\n------Both bureaucrats trying to sign-------" << std::endl;
    bur1.signForm(form);
    bur2.signForm(form);
    return (0);
}
