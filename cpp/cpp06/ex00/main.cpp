/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/19 10:47:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	ScalarConverter	sc;
	double			d = 0;

	if (ac != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if (ac == 2) {
		if (strlen(av[1]) == 1 && !isdigit(av[1][0]))
			d = static_cast<double>(av[1][0]);
		else {
			d = std::strtod(av[1], NULL); // interprete comme un double, passe les whitspaces etc
			std::cout << "d: " << d << std::endl;
		}
	}
	sc.convert(d);
	
	return 0;
}
