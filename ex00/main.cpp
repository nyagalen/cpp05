/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:47:01 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:55:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{

	try 
	{
		std::cout << "Trying to create a really badass bureaucrat"<< std::endl;
		Bureaucrat badass("Zero", 0);
		std::cout << "I'm sure he'll be created" << std::endl;
	}catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try 
	{
		std::cout << "Trying to create a more realistic bureaucrat and to promote them" << std::endl;
		Bureaucrat burPromotion("Career bitch", 2);
		std::cout << burPromotion << std::endl;
		burPromotion.increment();
	} catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\nLet's see if we create an unpromotable bureaucrat and still try to promote them?" << std::endl;
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
