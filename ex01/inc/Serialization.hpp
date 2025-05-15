/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:36:06 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/15 14:32:48 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include "Data.hpp"
#include <iostream>
#include <stdint.h> // for uintptr_t

#define GREEN "\033[32m"
#define RESET "\033[0m"
#define RED "\033[31m"

class Serializer
{
private:
    Serializer();
    Serializer(const Serializer &coppied);
    ~Serializer();
    Serializer &operator=(const Serializer &other);

public:
    static uintptr_t serialize(Data *ptr);
    static Data *deserialize(uintptr_t raw);
};

#endif