/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/25 14:41:56 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <string>
#include <iomanip>

class	Fixed
{
		public:			
				Fixed(void); // constructeur par defaut
				Fixed(const Fixed& copy); // constructeur de recopie 
				~Fixed(void); // destructeur
				Fixed &operator=(const Fixed& rhs); // operateur d'affectation

				// fonction
				int getRawBits(void) const;
				// void setRawBits(int const raw);

		private:
				int					_raw;
				static const int	_nbFrac = 8;

};

#endif