/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:17:05 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 14:40:42 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

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
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);	// not canonical but conveinient

#endif