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

// int dizisi için test fonksiyonu
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

// string dizisi için test fonksiyonu
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

// index erişim ve değişim testleri
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

// const array testi
void testConstArray() {
	std::cout << "[Test: Const Array]" << std::endl;
	const Array<int> constNumbers(3);
	std::cout << "Size: " << constNumbers.size() << std::endl;
	std::cout << constNumbers[0] << std::endl;
	// constNumbers[0] = 10; // bu satır derleme hatası verir, yorumda kalmalı
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
		std::cerr << "Unexpected exception: " << e.what() << std::endl << std::endl;
	}
	return 0;
}


/* 
#include <iostream>
#include <Array.hpp>

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */