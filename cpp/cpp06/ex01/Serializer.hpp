/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:47:03 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/22 15:23:12 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include <iostream>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

uintptr_t	serialize(Data* ptr);
Data*		deserialize(uintptr_t raw);
		
#endif