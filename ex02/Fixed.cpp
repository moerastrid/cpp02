/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:26:54 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 20:58:29 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : _rawBits(0)
{	
	//std::cout << "Default Constructor called" << std::endl;
}

Fixed::Fixed(int const value)
{
	this->_rawBits = value << _fractional_point;
	//std::cout << "Parametic Constructor called : int" << std::endl;
}

Fixed::Fixed(float const value)
{
	this->_rawBits = roundf(value * pow(2, _fractional_point));
	//std::cout << "Parametic Constructor called : float" << std::endl;
}

Fixed::Fixed(Fixed const & src) : _rawBits(0)
{
	//std::cout << "Copy Constructor called" << std::endl;
	*this = src;
}

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	//std::cout << "Assignation operator called" << std::endl;
	this->setRawBits(rhs.getRawBits());
	return (*this);
}

Fixed::~Fixed(void) 
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << " (getRawBits member function called) ";
	return (this->_rawBits);
}

void Fixed::setRawBits(int const raw)
{
	//std::cout << " (setRawBits member function called) ";
	this->_rawBits = raw;
}

float	Fixed::toFloat(void) const
{
	float	retval;

	retval = getRawBits() / pow(2, _fractional_point);
	return (retval);
}

int		Fixed::toInt(void) const
{
	int	retval = getRawBits() >> _fractional_point;
	return (retval);
}

std::ostream	&operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}

bool	Fixed::operator>(Fixed const &rhs)
{
	return (this->getRawBits() > rhs.getRawBits());
}

bool	Fixed::operator<(Fixed const &rhs)
{
	return (this->getRawBits() < rhs.getRawBits());
}

bool	Fixed::operator>=(Fixed const &rhs)
{
	return (this->getRawBits() >= rhs.getRawBits());
}

bool	Fixed::operator<=(Fixed const &rhs)
{
	return (this->getRawBits() <= rhs.getRawBits());
}

bool	Fixed::operator==(Fixed const &rhs)
{
	return (this->getRawBits() == rhs.getRawBits());
}

bool	Fixed::operator!=(Fixed const &rhs)
{
	return (this->getRawBits() != rhs.getRawBits());
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	float	total = this->toFloat() + rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	float	total = this->toFloat() - rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{
	float	total = this->toFloat() * rhs.toFloat();
	return (Fixed(total));
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	float	rawtotal = float(this->_rawBits) / float(rhs._rawBits);
	return (Fixed(rawtotal));
}
