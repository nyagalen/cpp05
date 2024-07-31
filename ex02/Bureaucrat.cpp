/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:56:41 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 19:45:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    std::cout << "Bureaucrat " << YELLOW << _name<< RESET << " created" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& copyMe): _name(copyMe._name), grade(copyMe.grade)
{}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &original)
{
    if (this != &original)
    {
        const_cast<std::string&>(this->_name) = original._name;
        this->grade = original.grade;
    }
    
    std::cout << "assignment constructor called" << std::endl;
    return *this;
}

Bureaucrat::~Bureaucrat()
{}

std::string Bureaucrat::getName() const
{
    return this->_name;
}

int Bureaucrat::getGrade() const{
    return this->grade;
}

void Bureaucrat::increment()
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrement()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

void Bureaucrat::executeForm(const AForm& form)
{
   // std::cout << "Hello from executeForm" << form.getName() << "Is it signed? " << form. isSigned() << std::endl;
    if (form.isSigned() == false)
        throw AForm::NotSignedException();
    if (form.getGradeExec() < grade)
        throw Bureaucrat::GradeTooLowException();
    std::cout <<CYAN << _name << RESET << " executing  " << form.getName() << std::endl;
    form.execute(*this);
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
    return o;
}