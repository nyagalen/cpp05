/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:14 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:52:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"


class	Bureaucrat
{
	private:
		std::string const _name;
		int	grade;
	
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat& copyMe);
		Bureaucrat(std::string name, int grade);
		Bureaucrat &operator=(const Bureaucrat &original);
		~Bureaucrat();
		std::string getName() const;
		int	getGrade() const;
		void increment();
		void decrement();

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char* what() const throw() { return RED"Grade too high\n" RESET; }
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return RED"Grade too low\n" RESET; }
		};
		
};
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);