/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:55 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:12:58 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	Form();
	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(Form const &other);
	Form &operator=(Form const &other);
	~Form();

	// Getter

	std::string getName() const;
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &bureaucrat);

	// Nested Exception classes
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what() const throw();
	};
};
std::ostream &operator<<(std::ostream &out, const Form &form);

#endif
