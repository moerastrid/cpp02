/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:26:54 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 14:11:25 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0)
{	
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value) : _value(value)
{
	std::cout << "Parametic Constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _value(0)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	this->_value = rhs.getRawBits();
	
	return (*this);
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const 
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_value = raw;
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.getRawBits();
	return (o);
}
