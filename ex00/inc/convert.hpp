/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 20:15:19 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/14 16:38:11 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
#define CONVERT_HPP
#include <iostream>

//convert.cpp
void printChar(char c);
void printInt(int i);
void printFloat(float f);
void printDouble(double d);
void printPseudoLiteral(const std::string &literal);
void printCharCheck(int n);

// CheckType.cpp

bool isChar(const std::string &literal);
bool isInt(const std::string &literal);
bool isFloat(const std::string &literal);
bool isDouble(const std::string &literal);
bool isPseudoLiteral(const std::string &literal);

std::string CheckType(const std::string &literal);

#endif