/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/08 16:31:20 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main() {

	std::vector<int> nb;
	nb.push_back(2);
	nb.push_back(1);
	nb.push_back(4);
	nb.push_back(5);
	nb.push_back(3);

	if (easyfind(nb, 1) == 1)
		std::cout << "nb found" << std::endl;
	else
		std::cout << "nb not found" << std::endl;

	return 0;
}