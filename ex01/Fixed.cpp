/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:26:54 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 14:52:16 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{	
	std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	this->_rawBits = value;
	std::cout << "Parametic Constructor called : int" << std::endl;
}

Fixed::Fixed(float const value) : _rawBits(value)
{
	std::cout << "Parametic Constructor called : float" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0)
{
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;

	this->setRawBits(rhs.getRawBits());
	
	return (*this);
}

Fixed::~Fixed(void) 
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	return (this->_rawBits);
}

int		Fixed::toInt(void) const
{
	int	retval = getRawBits();
	return (retval);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.getRawBits();
	return (o);
}