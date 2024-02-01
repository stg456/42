/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:40:36 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/22 15:24:33 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

uintptr_t serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
