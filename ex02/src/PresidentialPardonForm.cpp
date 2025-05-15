/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:13:53 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 14:53:31 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default")
{
	std::cout << GREEN << "Default constructor called for PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5), target(target)
{
	std::cout << GREEN << "Parameterized constructor called for PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), target(other.target)
{
	std::cout << GREEN << "Copy constructor called for PresidentialPardonForm" << RESET << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		this->target = other.target;
		std::cout << GREEN << "Copy assignment operator called for PresidentialPardonForm" << RESET << std::endl;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "Destructor called for PresidentialPardonForm" << RESET << std::endl;
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::cout << this->target << BLUE << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}

