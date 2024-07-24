/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:47:01 by svydrina          #+#    #+#             */
/*   Updated: 2024/06/15 23:25:17 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
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
