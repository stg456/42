/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/08 16:26:29 by stgerard         ###   ########.fr       */
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

	// std::vector<std::string> allo;
	// allo.push_back("allo");
	// allo.push_back("la");
	// allo.push_back("terre");
	// allo.push_back("ici");
	// allo.push_back("42");

	// if (easyfind(allo, "42") == 1)
	// 	std::cout << "42 found" << std::endl;
	// else
	// 	std::cout << "42 not found" << std::endl;

	return 0;
}