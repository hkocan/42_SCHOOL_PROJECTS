/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:56:23 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/26 10:14:14 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <iostream>

int main(void)
{

	std::string strArr[3] = {"Hello", "World", "!"};
	std::cout << "Before:" << std::endl;
	iter(strArr, 3, print);
	std::cout << "After tolower:" << std::endl;
	iter(strArr, 3, tolower);
	std::cout << "After toupper:" << std::endl;
	iter(strArr, 3, toupper);
	std::cout << "------------------" << std::endl;

	
	int arr[5] = {1, 2, 3, 4, 5};
	std::cout << "Before add:" << std::endl;
	iter(arr, 5, print);
	std::cout << "After add:" << std::endl;
	iter(arr, 5, add);
	std::cout << "------------------" << std::endl;

	char charArr[5] = {'H', 'e', 'l', 'l', 'o'};
	std::cout << "Before add:" << std::endl;
	iter(charArr, 5, print);
	std::cout << "After add:" << std::endl;
	iter(charArr, 5, add);
	std::cout << "------------------" << std::endl;

	float floatArr[3] = {1.1f, 2.2f, 3.3f};
	std::cout << "Before add:" << std::endl;
	iter(floatArr, 3, print);
	std::cout << "After add:" << std::endl;
	iter(floatArr, 3, add);
	std::cout << "------------------" << std::endl;

	double doubleArr[3] = {1.1, 2.2, 3.3};
	std::cout << "Before add:" << std::endl;
	iter(doubleArr, 3, print);
	std::cout << "After add:" << std::endl;
	iter(doubleArr, 3, add);
	std::cout << "------------------" << std::endl;

	return (0);
}