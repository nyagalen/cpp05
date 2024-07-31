/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:14 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 17:56:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

#define RED "\033[31m"

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
				virtual const char* what() const throw() { return RED"Grade too high\n"; }
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return RED"Grade too low\n"; }
		};
		
};
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);