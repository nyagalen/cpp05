/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:35:29 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/27 18:12:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int main(void)
{
    try
    {
        std::cout << "Creating first bureaucrat" << std::endl;
        Bureaucrat bur1("bur1", 100);
        std::cout << "Creating second bureaucrat" << std::endl;
        Bureaucrat bur2("bur2", 150);
        std::cout << "Creating a form" << std::endl;
        Form form("form", 130);
        std::cout << "Both bureaucrats trying to sign" << std::endl;
        form.beSigned(bur1);
        form.beSigned(bur2);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    return (0);
}
