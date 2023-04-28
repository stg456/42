/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/28 15:42:05 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class	Fixed
{
		public:			
				Fixed(void); // constructeur par defaut
				Fixed(const Fixed& copy); // constructeur de recopie 
				Fixed &operator=(const Fixed& rhs); // operateur d'affectation
				~Fixed(void); // destructeur
				
				Fixed(int const value);
				Fixed(float const value);
				float	toFloat(void) const;
				int		toInt(void) const;

				int		getRawBits(void) const;
				void	setRawBits(int const raw);

				bool operator>(const Fixed &rhs) const;
				bool operator<(const Fixed &rhs) const;
				bool operator<=(const Fixed &rhs) const;
				bool operator>=(const Fixed &rhs) const;
				bool operator==(const Fixed &rhs) const;
				bool operator!=(const Fixed &rhs) const;

				Fixed oprateur+(Fixed &rhs) const;
				Fixed oprateur-(Fixed &rhs) const;
				Fixed oprateur*(Fixed &rhs) const;
				Fixed oprateur/(Fixed &rhs) const;




		private:
				int					_fix;
				static const int	_frac = 8;
				
};

				std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif