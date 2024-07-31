/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:47:01 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 17:50:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try 
	{
		Bureaucrat burPromotion("Career bitch", 2);
		std::cout << burPromotion << std::endl;
		burPromotion.increment();
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bur("bur", 1);
		std::cout << bur << std::endl;
		bur.increment();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	return(0);
}
