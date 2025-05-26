/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 14:42:48 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/25 16:50:58 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <iostream>
#include <climits>
#include <sstream>

bool isScientific(double value) 
{
    std::ostringstream oss;
    oss << value;
    std::string str = oss.str();
    return str.find('e') != std::string::npos || str.find('E') != std::string::npos 
           || str.find('.') != std::string::npos;
}

void printCharCheck(int n)
{
    if (n < CHAR_MIN || n > CHAR_MAX) 
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    if (!isprint(n)) 
        std::cout << "char: Non displayable" << std::endl;
     else 
        std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
}

void printChar(char c)
{
    printCharCheck(static_cast<int>(c));
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
}

void printInt(int i)
{
    printCharCheck(i);
	std::cout << "int: " << i << std::endl;
    if (isScientific(static_cast<double>(i))) 
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    else 
        std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
    if (isScientific(static_cast<double>(i))) 
        std::cout << "double: " << static_cast<double>(i) << std::endl;
     else 
        std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
}

void printFloat(float f)
{
    printCharCheck(static_cast<int>(f));
   if(f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX)) 
        std::cout << "int: impossible" << std::endl;
     else 
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    if (isScientific(static_cast<double>(f))) 
        std::cout << "float: " << f << "f" << std::endl;
    else 
        std::cout << "float: " << f << ".0f" << std::endl;
    if (isScientific(static_cast<double>(f))) 
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    else 
        std::cout << "double: " << static_cast<double>(f) << ".0" << std::endl;
}

void printDouble(double d)
{
    printCharCheck(static_cast<int>(d));
    if(d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    if (isScientific(d)) 
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    else 
        std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
    if (isScientific(d))
        std::cout << "double: " << d << std::endl;
    else
        std::cout << "double: " << d << ".0" << std::endl;
}

void printPseudoLiteral(const std::string &literal)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    if(literal == "nan" || literal == "+inf" || literal == "-inf") 
    {
        std::cout << "float: " << literal << "f" << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }
    else if(literal == "nanf" || literal == "+inff" || literal == "-inff") 
    {
        std::cout << "float: " << literal  << std::endl;
        std::string doubleLiteral = literal.substr(0, literal.length() - 1);
        std::cout << "double: " << doubleLiteral << std::endl;
        return;
    }
}

