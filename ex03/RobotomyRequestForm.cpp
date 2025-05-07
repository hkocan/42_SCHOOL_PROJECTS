/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 01:03:41 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/07 02:50:10 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default")
{
	std::cout << GREEN << "Default constructor called for RobotomyRequestForm" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
	std::cout << GREEN << "Parameterized constructor called for RobotomyRequestForm" << RESET << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
	std::cout << GREEN << "Copy constructor called for RobotomyRequestForm" << RESET << std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		std::cout << GREEN << "Copy assignment operator called for RobotomyRequestForm" << RESET << std::endl;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "Destructor called for RobotomyRequestForm" << RESET << std::endl;
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!this->getIsSigned())
		throw FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw GradeTooLowException();
	std::srand(std::time(0)); // Seed the random number generator
	
	int i = std::rand();
	
	std::cout << "vvvzzzzz... drilling noises*" << std::endl;
	
	if(i % 2 == 0)
		std::cout << this->target << BLUE << " has been robotomized successfully ." << RESET << std::endl;
	else
		std::cout << this->target << BLUE << " has failed to be robotomized." << RESET << std::endl;
}
