/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:17:05 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 19:59:04 by ageels        ########   odam.nl         */
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

		Fixed	&operator=(Fixed const &rhs);					//canonical
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat(void) const;
		int		toInt(void) const;

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
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);	// not canonical but conveinient

#endif