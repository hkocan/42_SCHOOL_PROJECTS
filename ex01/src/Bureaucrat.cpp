/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:54:25 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:12:47 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("Default"), grade(GRADE_MIN)
{
	std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name)
{
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
	std::cout << "Parameterized constructor called" << std::endl;
}

// Copy constructor
Bureaucrat::Bureaucrat(Bureaucrat const &other) : name(other.name), grade(other.grade)
{
	std::cout << "Copy constructor called" << std::endl;
}

// Assignment operator
Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
	std::cout << "Destructor called" << std::endl;
}

// Getter functions
std::string Bureaucrat::getName() const
{
	return this->name;
}

int Bureaucrat::getGrade() const
{
	return this->grade;
}

// Setter functions
void Bureaucrat::setGrade(int grade)
{
	if (grade < GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->grade <= GRADE_MAX)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->grade >= GRADE_MIN)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high! It must be 1 or lower.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low! It must be 150 or higher.";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	return out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName() << " couldn't sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}
