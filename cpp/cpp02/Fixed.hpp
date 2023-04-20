/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:59:06 by stgerard          #+#    #+#             */
/*   Updated: 2023/04/20 18:25:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class	Fixed
{
		public:
				// constructeur
				Fixed(void);

				~Fixed(void);

				// fonction
				int getRawBits(void) const;
				void setRawBits(int const raw);

		private:
				int	nbFix;
				static const int	bitFrac;

};

#endif