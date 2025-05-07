/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:14 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/07 03:10:15 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "AForm.hpp"

int main()
{
	Intern intern;
	std::string formNames[] = {
		"ShrubberyCreationForm",
		"RobotomyRequestForm",
		"PresidentialPardonForm",
		"CoffeeMakingForm" // form not found
	};
	try
	{
		for (int i = 0; i < 4; ++i)
		{
			std::cout << "\nTrying to create: " << formNames[i] << std::endl;
			AForm *form = intern.makeForm(formNames[i], "TargetX");

			if (form)
			{
				std::cout << "Form created: " << form->getName() << std::endl;
				delete form;
			}
			else
			{
				std::cout << "Form creation failed." << std::endl;
			}
			std::cout << "---------------------------------" << std::endl;
		}
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}
