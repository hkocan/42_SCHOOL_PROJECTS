/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 18:35:54 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 15:12:57 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

// constructor
ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), target("default")
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	: AForm("ShrubberyCreationForm", 145, 137), target(target)
{
	std::cout << GREEN << "ShrubberyCreationForm constructor called" << RESET << std::endl;
}

// copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)
	: AForm(other), target(other.target)
{
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;
}
// copy assignment operator
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
	{
		AForm::operator=(other);
		//this->target = other.target; // const
		std::cout << GREEN << "ShrubberyCreationForm copy assignment operator called" << RESET << std::endl;
	}
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
	{
		throw AForm::FormNotSignedException();
	}
	if (executor.getGrade() > getGradeToExecute())
	{
		throw AForm::GradeTooLowException();
	}
	std::ofstream outFile((target + "_shrubbery").c_str());
	if (!outFile)
	{
		std::cerr << "Error opening file" << std::endl;
		return;
	}
	outFile << "       *\n"
			<< "      ***\n"
			<< "     *****\n"
			<< "    *******\n"
			<< "   *********\n"
			<< "      |||\n";
}
