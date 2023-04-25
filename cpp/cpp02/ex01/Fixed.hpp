/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/25 16:37:54 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>

class	Fixed
{
		public:			
				Fixed(void); // constructeur par defaut
				Fixed(const Fixed& copy); // constructeur de recopie 
				~Fixed(void); // destructeur
				Fixed &operator=(const Fixed& rhs); // operateur d'affectation
				Fixed &operator<<(const Fixed& rhs);
				Conv1(const int);
				Conv2(const float);

				// fonction
				int getRawBits(void) const;
				void setRawBits(int const raw);
				float toFloat( void ) const;
				int toInt( void ) const;

		private:
				int					_fix;
				static const int	_frac = 8;

				
};

#endif