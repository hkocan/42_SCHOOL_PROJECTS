/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkocan <haticekocan97@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 01:07:51 by hkocan            #+#    #+#             */
/*   Updated: 2025/05/26 09:40:21 by hkocan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "whatever.hpp"

int main( void ) 
{
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::cout << "-------------------------------" << std::endl;

	float x = 4.2f;
	float y = 3.14f;
	::swap( x, y );
	std::cout << "x = " << x << ", y = " << y << std::endl;
	std::cout << "min( x, y ) = " << ::min( x, y ) << std::endl;
	std::cout << "max( x, y ) = " << ::max( x, y ) << std::endl;
	std::cout << "-------------------------------" << std::endl;

	char p = 'a';
	char q = 'b';
	::swap( p, q );
	std::cout << "p = " << p << ", q = " << q << std::endl;
	std::cout << "min( p, q ) = " << ::min( p, q ) << std::endl;
	std::cout << "max( p, q ) = " << ::max( p, q ) << std::endl;
	std::cout << "-------------------------------" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	std::cout << "-------------------------------" << std::endl;
	
	return 0;
}