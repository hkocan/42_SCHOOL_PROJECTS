/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:15:08 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/15 14:34:36 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "convert.hpp"
#include <iostream>
#include <cstdlib> // strtol, strtod

// Private methods
ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter &other) { *this = other; }

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter() {}

// Public method
void ScalarConverter::convert(const std::string &literal)
{
	std::string ScalarType = CheckType(literal);
	std::cout << "The type of the literal is: " << ScalarType << std::endl;

	if (ScalarType == "char")
		printChar(literal[1]);
	else if (ScalarType == "int")
	{
		char *end;
		long i = strtol(literal.c_str(), &end, 10);
		if (*end != '\0')
			std::cout << "Invalid literal for int" << std::endl;
		else
			printInt(static_cast<int>(i));
	}
	else if (ScalarType == "float")
	{
		std::string core = literal.substr(0, literal.length() - 1); // remove 'f'
		char *end;
		double value = strtod(core.c_str(), &end);

		if (*end != '\0')
			std::cout << "Invalid literal for float" << std::endl;
		else
			printFloat(static_cast<float>(value));
	}
	else if (ScalarType == "double")
	{
		char *end;
		double value = strtod(literal.c_str(), &end);

		if (*end != '\0')
			std::cout << "Invalid literal for double" << std::endl;
		else
			printDouble(value);
	}
	else if (ScalarType == "pseudo-literal")
		printPseudoLiteral(literal);
	else
		std::cout << "Invalid literal" << std::endl;
}
