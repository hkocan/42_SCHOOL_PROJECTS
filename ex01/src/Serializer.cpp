/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 23:36:02 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/15 14:32:37 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer &copied) { *this = copied; }

Serializer::~Serializer() {}

Serializer &Serializer::operator=(const Serializer &other)
{
	(void)other;
	return *this;
}

uintptr_t Serializer::serialize(Data *ptr)
{
	std::cout << GREEN << "Serialize function called" << RESET << std::endl;
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	std::cout << GREEN << "Deserialize function called" << RESET << std::endl;
	return reinterpret_cast<Data *>(raw);
}
