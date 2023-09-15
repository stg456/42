/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:10:11 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 12:42:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>

class Convert
{
	public:
		Convert();
		Convert(const Convert & copy);
		Convert & operator = (const Convert & rhs);
		~Convert();

		void	ft_convert(double nb)
};

#endif