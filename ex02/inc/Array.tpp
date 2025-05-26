/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <hkocan@student.42.fr>              #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-05-26 13:30:10 by hkocan            #+#    #+#             */
/*   Updated: 2025-05-26 13:30:10 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"
#include <iostream>

template <typename T>
Array<T>::Array() : data(0), len(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), len(n) {}

template <typename T>
Array<T>::Array(const Array& other) : data(new T[other.len]), len(other.len) {
    for (unsigned int i = 0; i < len; ++i)
        data[i] = other.data[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& other) 
{
    if (this != &other) 
    {
        delete[] data;
        len = other.len;
        data = new T[len];
        for (unsigned int i = 0; i < len; ++i)
            data[i] = other.data[i];
    }
    return *this;
}

template <typename T>
Array<T>::~Array() {
    delete[] data;
}

template <typename T>
T& Array<T>::operator[](int index) {
    if(index < 0 || static_cast<unsigned int>(index) >= len)
        throw IndexOutOfBoundsException();
    return data[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || static_cast<unsigned int>(index) >= len)
        throw IndexOutOfBoundsException();
    return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
    return len;
}

template <typename T>
const char* Array<T>::IndexOutOfBoundsException::what() const throw() {
    return "Index out of bounds";
}

