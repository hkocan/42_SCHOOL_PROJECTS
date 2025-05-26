/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 20:06:13 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/23 15:17:32 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

#include "Array.hpp"
#include <iostream>
#include <string>

// int test
void testIntArray() {
	std::cout << "[Test: Int Array]" << std::endl;
	Array<int> intArray(10);
	for (unsigned int i = 0; i < intArray.size(); i++)
		intArray[i] = i + 1;

	for (unsigned int i = 0; i < intArray.size(); i++)
		std::cout << intArray[i] << " ";
	std::cout << "\nSize: " << intArray.size() << "\n\n";
	std::cout << "--------------------------" << std::endl;
}

// string test
void testStringArray() {
	std::cout << "[Test: String Array]" << std::endl;
	Array<std::string> strArray(3);
	strArray[0] = "Hello";
	strArray[1] = "World";
	strArray[2] = "!";

	for (unsigned int i = 0; i < strArray.size(); i++)
		std::cout << strArray[i] << " ";
	std::cout << "\nSize: " << strArray.size() << "\n\n";
	std::cout << "--------------------------" << std::endl;
}

// index test
void testAccessAndModify() {
	std::cout << "[Test: Access & Modify]" << std::endl;
	Array<int> numbers(5);
	numbers[0] = 10;
	numbers[1] = 20;
	numbers[2] = 30;

	std::cout << "Before: " << numbers[2] << std::endl;
	numbers[2] = 5;
	std::cout << "After: " << numbers[2] << std::endl << std::endl;
	std::cout << "--------------------------" << std::endl;
}

// const array test
void testConstArray() {
	std::cout << "[Test: Const Array]" << std::endl;


	Array<int> tempNumbers(3);
	tempNumbers[0] = 1;
	tempNumbers[1] = 2;
	tempNumbers[2] = 3;

	const Array<int> constNumbers = tempNumbers;

	std::cout << "Size: " << constNumbers.size() << std::endl;
	std::cout << constNumbers[0] << std::endl;
	std::cout << constNumbers[1] << std::endl;
	std::cout << constNumbers[2] << std::endl;

	// constNumbers[0] = 10;
	std::cout << "--------------------------" << std::endl;
}


// out-of-bounds testi
void testIndexOutOfBounds() {
	std::cout << "[Test: Index Out of Bounds]" << std::endl;
	Array<int> arr(3);
	arr[10] = 1;
	std::cout << std::endl;
}

int main() {
	try {
		testIntArray();
		testStringArray();
		testAccessAndModify();
		testConstArray();
		testIndexOutOfBounds();
	}
	catch (const std::exception& e) {
		std::cerr << "Exception: " << e.what() << std::endl << std::endl;
	}
	return 0;
}
