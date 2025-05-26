/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/18 19:57:02 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/26 10:30:22 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>

template <typename T>
class Array {
private:
    T* data;
    unsigned int len;

public:
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    Array& operator=(const Array& other);
    ~Array();

    T& operator[](int index);
    const T& operator[](int index) const;

    unsigned int size() const;

    class IndexOutOfBoundsException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

#include "Array.tpp"

#endif
