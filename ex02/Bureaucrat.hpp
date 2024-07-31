/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:56:28 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 18:21:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

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
            virtual const char* what() const throw() {return RED"Grade too high\n";}
    };

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {return RED"Grade too low\n"; }
    };
    
};

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs);
