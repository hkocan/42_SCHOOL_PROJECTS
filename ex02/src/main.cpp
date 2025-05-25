/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 01:40:00 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/25 17:56:08 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate();
void identify(Base *p);
void identify(Base &p);

int main()
{
    Base *obj = generate();
    // obj = new Base();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}
