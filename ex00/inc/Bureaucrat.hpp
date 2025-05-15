/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 18:54:30 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/04 01:12:33 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define GRADE_MAX 1
#define GRADE_MIN 150

#include <iostream>

// **********************     Bureaucrat Class     ************************* */

class Bureaucrat
{
private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(Bureaucrat const &src);
	Bureaucrat &operator=(Bureaucrat const &other);
	~Bureaucrat();

	std::string getName() const;
	int getGrade() const;

	void setGrade(int grade);
	void incrementGrade();
	void decrementGrade();

	// *** Nested Exception Classes ***
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
std::ostream &operator<<(std::ostream &out, Bureaucrat const &Bureaucrat);

#endif

/* ************************************************************************** */