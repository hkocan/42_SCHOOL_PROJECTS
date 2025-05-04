/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 15:23:03 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 15:49:30 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << GREEN << "Intern copy assignment operator called" << RESET << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target)
{
	AForm *form = NULL;

	if (formName == "ShrubberyCreationForm")
		form = new ShrubberyCreationForm(target);
	else if (formName == "RobotomyRequestForm")
		form = new RobotomyRequestForm(target);
	else if (formName == "PresidentialPardonForm")
		form = new PresidentialPardonForm(target);
	else
		std::cout << RED << "Intern: Form not found" << RESET << std::endl;
	return form;
}
