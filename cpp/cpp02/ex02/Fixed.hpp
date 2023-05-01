/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/01 16:21:32 by stgerard         ###   ########.fr       */
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

				Fixed operator+(Fixed &rhs) const;
				Fixed operator-(Fixed &rhs) const;
				Fixed operator*(Fixed &rhs) const;
				Fixed operator/(Fixed &rhs) const;

				// ++a
				Fixed &operator++(void);
				Fixed &operator--(void);

				// a++
				Fixed operator++(int);
				Fixed operator--(int);

				static Fixed &min(int &a, int &b);
				static Fixed const &min(int const &a, int const &b);
				
				static Fixed &max(int &a, int &b);
				static const fixed &max(int const &a, int const &b);


		private:
				int					_fix;
				static const int	_frac = 8;
				
};

				std::ostream &operator<<(std::ostream &out, const Fixed &rhs);

#endif