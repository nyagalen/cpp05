/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:58:21 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:32:28 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int gradeSign;
		const int gradeExec;
	public:
		AForm();
		AForm(const std::string name, int gradeSign);
        AForm(const std::string name, int gradeSign, int gradeExec);
		AForm(const AForm& copyMe);
		AForm &operator=(const AForm &original);
		virtual ~AForm();
		std::string getName() const;
		bool isSigned() const;
		int getGradeSign() const;
		int getGradeExec() const;
		void beSigned(Bureaucrat& bureaucrat);
        virtual void execute(const Bureaucrat &executor) const = 0;

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

    class NotSignedException : public std::exception
    {
        public:
            virtual const char* what() const throw() { return RED "Form not signed\n" RESET;}
    };
		
};
std::ostream& operator<<(std::ostream& o, const AForm& rhs);

