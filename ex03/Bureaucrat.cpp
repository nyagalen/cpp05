/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 18:56:41 by svydrina          #+#    #+#             */
/*   Updated: 2024/07/31 20:51:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Bureaucrat.hpp"

#define CYAN "\033[36m"
#define RESET "\033[0m"

Bureaucrat::Bureaucrat()
{}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), grade(grade)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
   // std::cout << "name/grade constructor called" << std::endl;
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
    // if (form.isSigned() == false)
    //     throw AForm::NotSignedException();
    // if (form.getGradeExec() < grade)
    //     throw Bureaucrat::GradeTooLowException();
    std::cout << CYAN << _name << RESET << " is executing " << form.getName() << std::endl;
    form.execute(*this);
}

std::ostream& operator<<(std::ostream& o, const Bureaucrat& rhs)
{
    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".\n";
    return o;
}