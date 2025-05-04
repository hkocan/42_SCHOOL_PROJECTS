/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:44:35 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 14:43:23 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
AForm::AForm()
	: name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << GREEN << "AForm Default constructor called" << RESET << std::endl;
}

// Parameterized Constructor
AForm::AForm(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw AForm::GradeTooLowException();
	std::cout << GREEN << "AForm Parameterized constructor called" << RESET << std::endl;
}

// Copy Constructor
AForm::AForm(AForm const &other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << GREEN << "AForm Copy constructor called" << RESET << std::endl;
}

// Assignment Operator
// Only isSigned can be assigned because other attributes are const
AForm &AForm::operator=(AForm const &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
		std::cout << GREEN << "AForm Assignment operator called" << RESET << std::endl;
	}
	return *this;
}

// Destructor
AForm::~AForm()
{
	std::cout << RED << "AForm Destructor called" << RESET << std::endl;
}

// Getter Functions
std::string AForm::getName() const
{
	return this->name;
}

bool AForm::getIsSigned() const
{
	return this->isSigned;
}

int AForm::getGradeToSign() const
{
	return this->gradeToSign;
}

int AForm::getGradeToExecute() const
{
	return this->gradeToExecute;
}

// beSigned function
void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

// Exception Classes
const char *AForm::GradeTooHighException::what() const throw()
{
	return "AForm grade is too high!";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "AForm grade is too low!";
}
const char *AForm::FormNotSignedException::what() const throw()
{
	return "AForm is not signed!";
}

// Overloaded << operator
std::ostream &operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << BLUE << "\"" << form.getName() << "\"" << RESET;
	if (form.getIsSigned())
		out << ", is signed, ";
	else
		out << ", is not signed, ";
	out << "grade required to sign: " << form.getGradeToSign() << ", ";
	out << "grade required to execute: " << form.getGradeToExecute();
	return out;
}
