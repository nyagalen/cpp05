/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:56:28 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/30 00:50:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat
{
    private:
        std::string const _name;
        int grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copyMe);
        Bureaucrat(std::string name, int grade);
        Bureaucrat &operator=(const Bureaucrat &original);
        ~Bureaucrat();
        std::string getName() const;
        int getGrade() const;
        void increment();
        void decrement();
        void executeForm(const AForm& form);

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade too high\n";}
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return "Grade too low\n"; }
    };
    
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);
