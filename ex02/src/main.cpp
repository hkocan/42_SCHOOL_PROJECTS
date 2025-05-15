/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:14 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 15:37:24 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
    
    try
    {
        Bureaucrat ali("Ali", 100);
        ShrubberyCreationForm form("aaaaa");

        std::cout << form << std::endl;

        ali.signForm(form);

        ali.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat veli("Veli", 138);
        ShrubberyCreationForm form("aaabb");

        std::cout << form << std::endl;

        veli.signForm(form);

        veli.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;

    try
    {
        Bureaucrat mehmet("Mehmet", 40);
        RobotomyRequestForm form("Robotomy");

        std::cout << form << std::endl;

        mehmet.signForm(form);

        mehmet.executeForm(form);
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;
  
    try
    {
        Bureaucrat mehmet("Mehmet", 40);
        PresidentialPardonForm form("Robotomy");
        
        std::cout << form << std::endl;
        
        mehmet.signForm(form);
        
        mehmet.executeForm(form);
        
    }
    catch(const std::exception& e)
    {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    
    return 0;
}
