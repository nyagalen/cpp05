/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <svydrina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:43:14 by svydrina          #+#    #+#             */
/*   Updated: 2024/05/27 19:16:15 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

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
				virtual const char* what() const throw() { return "Grade too high\n"; }
		};
		
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char* what() const throw() {return "Grade too low\n"; }
		};
		
};
std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);