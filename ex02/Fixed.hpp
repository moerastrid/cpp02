/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:17:05 by ageels        #+#    #+#                 */
/*   Updated: 2024/02/27 13:46:18 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>
# include <cmath>

class	Fixed {
	private :
		int					_rawBits;
		static const int	_fractional_point = 8;

	public :
		Fixed(void);											//canonical
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const & src);								//canonical
		~Fixed(void);											//canonical

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

		Fixed	&operator=(Fixed const &rhs);					//canonical
		
		bool	operator>(Fixed const &rhs);
		bool	operator<(Fixed const &rhs);
		bool	operator>=(Fixed const &rhs);
		bool	operator<=(Fixed const &rhs);
		bool	operator==(Fixed const &rhs);
		bool	operator!=(Fixed const &rhs);

		Fixed	operator+(Fixed const &rhs) const;
		Fixed	operator-(Fixed const &rhs) const;
		Fixed	operator*(Fixed const &rhs) const;
		Fixed	operator/(Fixed const &rhs) const;

		Fixed	&operator++();		//Prefix increment operator
		Fixed	operator++(int);	//Postfix increment operator
		Fixed	&operator--();		//Prefix decrement operator
		Fixed	operator--(int);	//Postfix decrement operator

		// static member functions
		static Fixed const	&min(Fixed const &fa, Fixed const &fb);
		static Fixed 		&min(Fixed &fa, Fixed &fb);
		static Fixed const	&max(Fixed const &fa, Fixed const &fb);
		static Fixed		&max(Fixed &fa, Fixed &fb);		
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);	// not canonical but conveinient

#endif