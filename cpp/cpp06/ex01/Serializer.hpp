/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:47:03 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/22 14:08:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& copy);
		~Serializer();
		Serializer& operator = (const Serializer &src);

		uintptr_t	serialize(Data* ptr);
		Data*		deserialize(uintptr_t raw);
};

#endif