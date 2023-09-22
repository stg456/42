/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:40:36 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/22 14:08:01 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serializer.hpp"

Serializer::Serializer() {}

Serializer::Serializer(const Serializer& copy) {
	*this = copy;
}

Serializer::~Serializer() {}

Serializer& Serializer::operator = (const Serializer &rhs) {
	if (this == &rhs)
		return *this;
	return *this;
}


uintptr_t Serializer::serialize(Data* ptr) {
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
	return reinterpret_cast<Data*>(raw);
}
