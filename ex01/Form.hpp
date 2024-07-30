/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:36:45 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/30 16:04:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

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
			virtual const char* what() const throw() {return "Grade too high\n";}
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw() {return "Grade too low\n";}
	};	
		
};
std::ostream& operator<<(std::ostream& o, const Form& rhs);