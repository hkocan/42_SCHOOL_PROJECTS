/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identify.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:39:57 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/25 17:54:49 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

// Rastgele bir Base pointer üret
Base* generate()
{
    std::srand(std::time(NULL));
    int r = std::rand() % 3; 
    switch (r)
    {
        case 0: 
            return new A();
        case 1: 
            return new B();
        case 2: 
            return new C();
    }
    return NULL;
}

// Pointer ile tür tanımlama
void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}

// Referans ile tür tanımlama
void identify(Base& p)
{
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception &e){}

    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception &e){}

    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception &e){}

    std::cout << "Unknown type" << std::endl;
}
