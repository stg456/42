/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/04 14:02:39 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

#include <iostream>

// void print(int const & x) {
// 	std::cout << x << " ";
// }

// void print(std::string const & x) {
// 	std::cout << x << " ";
// }

template <typename T> // neccessite :: pour l'instantiation
void print(T const & x) {
	std::cout << x << " ";
}

int main( void ) {
	{
	int array[5] = { 0, 1, 2, 3, 42 };
	::iter(array, 5, &print);

	std::cout << std::endl;
	}
	{
	std::string array2[5] = { "hello", "42", "on", "the", "world" };
	::iter(array2, 5, &print);

	std::cout << std::endl;
	}
	return 0;
}
