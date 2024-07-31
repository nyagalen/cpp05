/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:36:45 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 23:22:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int gradeSign;
		const int gradeExec;
	public:
		Form();
		Form(const std::string name, int gradeSign);
		Form(const Form& copyMe);
		Form &operator=(const Form &original);
		~Form();
		std::string getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat& bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw() {return RED"Grade too high\n" RESET;}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() {return RED"Grade too low\n" RESET;}
	};	
		
};
std::ostream& operator<<(std::ostream& o, const Form& rhs);