/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 23:35:49 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 19:02:42 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Form;

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
        void signForm(Form& form);
        

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return RED"Grade too high\n";}
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return RED"Grade too low\n"; }
    };
    
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);
