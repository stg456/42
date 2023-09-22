/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/22 16:44:49 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identify.hpp"
#include <iostream>

int main()
{
	Data* data = new Data;

	data->s1 = "Hello";
	data->n = 42;
	data->s2 = "World";

	std::cout << "Data: " << data->s1 << " " << data->n << " " << data->s2 << std::endl;

	uintptr_t raw = serialize(data);

	std::cout << "Raw: " << raw << std::endl;

	Data* data2 = deserialize(raw);

	std::cout << "Data: " << data2->s1 << " " << data2->n << " " << data2->s2 << std::endl;

	delete data;

	return 0;
}
