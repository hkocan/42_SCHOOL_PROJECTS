/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:50:14 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 15:50:59 by hkocan           ###   ########.fr       */
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
		"CoffeeMakingForm"  // Geçersiz form
	};

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
			std::cout << "Form creation failed." << std::endl;
	}
	return 0;
}


