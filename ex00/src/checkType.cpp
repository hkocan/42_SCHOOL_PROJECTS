/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkType.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-26 05:23:46 by hkocan            #+#    #+#             */
/*   Updated: 2025-05-26 05:23:46 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert.hpp"
#include <climits>
#include <cstdlib>
#include <cerrno>
#include <limits>

bool isChar(const std::string &literal)
{
    return literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'' 
            && static_cast<unsigned char>(literal[1]) < 128;
}

bool isInt(const std::string &literal)
{
    size_t i = 0;
    if (literal.empty())
        return false;

    if (literal[0] == '-' || literal[0] == '+')
    {
        if (literal.length() == 1)
            return false;
        i = 1;
    }
    for (; i < literal.length(); ++i)
    {
        if (!isdigit(literal[i]))
            return false;
    }
    char *end;
    long val = std::strtol(literal.c_str(), &end, 10);
    return *end == '\0' && val >= INT_MIN && val <= INT_MAX;
}

bool isFloat(const std::string &literal)
{
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;

    std::string core = literal.substr(0, literal.length() - 1);

    errno = 0;
    char *end;
    double value = std::strtod(core.c_str(), &end);

    if (*end != '\0')
        return false;

    if (core.find('.') == std::string::npos &&
        core.find('e') == std::string::npos &&
        core.find('E') == std::string::npos)
        return false;

    return errno != ERANGE &&
           value >= -std::numeric_limits<float>::max() &&
           value <= std::numeric_limits<float>::max();
}

bool isDouble(const std::string &literal)
{
    errno = 0;
    char *end;
    double value = std::strtod(literal.c_str(), &end);

    if (*end != '\0')
        return false;

    if (literal.find('.') == std::string::npos &&
        literal.find('e') == std::string::npos &&
        literal.find('E') == std::string::npos)
        return false;

    return errno != ERANGE &&
           value >= -std::numeric_limits<double>::max() &&
           value <= std::numeric_limits<double>::max();
}

bool isPseudoLiteral(const std::string &literal)
{
    return literal == "nan" || literal == "+inf" || literal == "-inf" ||
           literal == "nanf" || literal == "+inff" || literal == "-inff";
}

std::string CheckType(const std::string &literal)
{
    if (isPseudoLiteral(literal))
        return "pseudo-literal";
    if (isChar(literal))
        return "char";
    if (isInt(literal))
        return "int";
    if (isFloat(literal))
        return "float";
    if (isDouble(literal))
        return "double";
    return "Invalid type";
}
