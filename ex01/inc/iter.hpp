/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 15:56:53 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/26 10:11:42 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
#include <iostream>

template <typename T>
void toupper(T& element) {
	for (size_t i = 0; i < element.length(); i++) {
		if (element[i] >= 'a' && element[i] <= 'z') {
			element[i] -= 32;
		}
	}
	std::cout << element << std::endl;
}

template <typename T>
void tolower(T& element) {
	for (size_t i = 0; i < element.length(); i++) {
		if (element[i] >= 'A' && element[i] <= 'Z') {
			element[i] += 32;
		}
	}
	std::cout << element << std::endl;
}

template <typename T>
void add(T& element) {
	element += 1;
	std::cout << element << std::endl;
}

template <typename T>
void print(T& element) {
	std::cout << element << std::endl;
}

template <typename T>
void iter(T* array, size_t length, void (*func) (T& ))
{
	for(size_t i = 0; i < length; i++)
		func(array[i]);
}

#endif
