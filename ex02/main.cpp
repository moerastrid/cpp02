/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:16:51 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 20:55:32 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void	previous_ex_tests(Fixed const a, Fixed const b, Fixed const c, Fixed const d)
{
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	std::cout << "d is " << d.toInt() << " as integer" << std::endl;
}

void	current_ex_tests(Fixed a, Fixed const b)
{
	std::cout << "test a\t" << a << std::endl;
	std::cout << "test b\t" << b << std::endl;
	//std::cout << ++a << std::endl;
	//std::cout << a << std::endl;
	//std::cout << a++ << std::endl;
	//std::cout << a << std::endl;
	//std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
}

void	comparison_tests(Fixed a, Fixed const b)
{
	std::cout << "a > b\t" << (a > b) << std::endl;
	std::cout << "a < b\t" << (a < b) << std::endl;
	std::cout << "a >= b\t" << (a >= b) << std::endl;
	std::cout << "a <= b\t" << (a <= b) << std::endl;
	std::cout << "a <= b\t" << (a <= b) << std::endl;
	std::cout << "a == b\t" << (a == b) << std::endl;
	std::cout << "a != b\t" << (a != b) << std::endl;
}

void	arithmetic_tests(Fixed const b, Fixed const c)
{
	std::cout << "b + c\t" << (b + c) << std::endl;
	std::cout << "b - c\t" << (b - c) << std::endl;
	std::cout << "b * c\t" << (b * c) << std::endl;
	std::cout << "c / b\t" << (c / b) << std::endl;
}

int main( void ) {
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.42f );
	Fixed const d( b );
	Fixed e;
	Fixed f;
	//Fixed const f( Fixed( 5.05f ) * Fixed( 2 ) );

	a = Fixed( 1234.4321f );
	previous_ex_tests(a, b, c, d);
	current_ex_tests(e, f);
	comparison_tests(a, b);
	arithmetic_tests(b, c);
	return (0);
}