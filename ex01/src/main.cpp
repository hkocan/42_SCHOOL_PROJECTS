/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:14 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:13:01 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

int main()
{
    try
    {
        Bureaucrat bureaucrat("Ali", 50);
        Form form("Important Form", 60, 30);

        std::cout << bureaucrat << std::endl;
        std::cout << form << std::endl;

        bureaucrat.signForm(form);
        std::cout << form << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    std::cout << "---------------------------------" << std::endl;

    try
    {
        Bureaucrat bureaucrat2("Veli", 100);
        Form form2("Secret Form", 90, 40);

        std::cout << bureaucrat2 << std::endl;
        std::cout << form2 << std::endl;

        bureaucrat2.signForm(form2);
        std::cout << form2 << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
