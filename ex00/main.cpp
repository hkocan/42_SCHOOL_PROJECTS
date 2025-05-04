/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:14 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:12:39 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat b1("Alice", 50);
        std::cout << b1 << std::endl;

        b1.incrementGrade();
        std::cout << "After increment: " << b1 << std::endl;

        b1.decrementGrade();
        std::cout << "After decrement: " << b1 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Caught exception b1: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Caught exception b1: " << e.what() << std::endl;
    }
    try
    {
        Bureaucrat b2("Bob", 0);
        std::cout << b2 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Caught exception b2: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Caught exception b2: " << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b3("Charlie", 160);
        std::cout << b3 << std::endl;
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cout << "Caught exception b3: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cout << "Caught exception b3: " << e.what() << std::endl;
    }
    return 0;
}
