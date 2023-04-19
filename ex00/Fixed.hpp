/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ageels <ageels@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/19 12:17:05 by ageels        #+#    #+#                 */
/*   Updated: 2023/04/19 13:26:28 by ageels        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H

# include <iostream>

class	Fixed {
	private :
		int					_value;
		static const int	_bits = 8;

	public :
		Fixed(void);											//canonical
		Fixed(int const value);
		Fixed(Fixed const & src);								//canonical
		~Fixed(void);											//canonical

		Fixed	&operator=(Fixed const &rhs);					//canonical
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

std::ostream	&operator<<(std::ostream &o, Fixed const &i);	// not canonical but conveinient

#endif