/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:35:55 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/25 17:45:18 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include "Data.hpp"

int main()
{
    Data myData;
    myData.name = "Ali";
    myData.address = "Gebze/Kocaeli";
    myData.age = 17;

    std::cout << "Original Data Address: " << &myData << std::endl;
    std::cout << "Name: " << myData.name << ", Age: " << myData.age << ", Address: "
              << myData.address << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    uintptr_t serialized = Serializer::serialize(&myData);
    std::cout << "Serialized Data Address: " << serialized << std::endl;
    std::cout << "--------------------------------------------" << std::endl;

    myData.name = "Veli";
    myData.age = 20;
    myData.address = "Istanbul";

    std::cout << "Modified Name: " << myData.name << ", Age: " << myData.age
              << ", Address: " << myData.address << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    Data *deserialized = Serializer::deserialize(serialized);

    std::cout << "Deserialized Data Address: " << deserialized << std::endl;
    std::cout << "After Deserialization:" << std::endl;
    std::cout << "Name: " << deserialized->name << ", Age: " << deserialized->age
              << ", Address: " << deserialized->address << std::endl;
    std::cout << "-----------------------------------------" << std::endl;

    if (deserialized == &myData)
        std::cout << GREEN << "Success: The deserialized pointer matches the original!" << RESET << std::endl;
    else
        std::cout << RED << "Error: Pointer mismatch!" << RESET << std::endl;
    return 0;
}
