/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:44:35 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:12:55 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Default Constructor
Form::Form()
	: name("Default Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
	std::cout << "Form Default constructor called" << std::endl;
}

// Parameterized Constructor
Form::Form(std::string name, int gradeToSign, int gradeToExecute)
	: name(name), isSigned(false), gradeToSign(gradeToSign),
	  gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExecute > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form Parameterized constructor called" << std::endl;
}

// Copy Constructor
Form::Form(Form const &other)
	: name(other.name), isSigned(other.isSigned),
	  gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
	std::cout << "Form Copy constructor called" << std::endl;
}

// Assignment Operator
// Only isSigned can be assigned because other attributes are const
Form &Form::operator=(Form const &other)
{
	if (this != &other)
	{
		this->isSigned = other.isSigned;
	}
	return *this;
}

// Destructor
Form::~Form()
{
	std::cout << "Form Destructor called" << std::endl;
}

// Getter Functions
std::string Form::getName() const
{
	return this->name;
}

bool Form::getIsSigned() const
{
	return this->isSigned;
}

int Form::getGradeToSign() const
{
	return this->gradeToSign;
}

int Form::getGradeToExecute() const
{
	return this->gradeToExecute;
}

// beSigned function
void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > this->gradeToSign)
		throw Form::GradeTooLowException();

	this->isSigned = true;
}

// Exception Classes
const char *Form::GradeTooHighException::what() const throw()
{
	return "Form grade is too high!";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Form grade is too low!";
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\", ";
	if (form.getIsSigned())
		out << "is signed, ";
	else
		out << "is not signed, ";
	out << "grade required to sign: " << form.getGradeToSign() << ", ";
	out << "grade required to execute: " << form.getGradeToExecute();
	return out;
}
