/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/18 13:35:55 by stgerard         ###   ########.fr       */
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
	else {
		if (strlen(av[1]) && !isdigit(*av[1]))
		d = std::strtod(av[1], NULL); // interprete comme un double, passe les whitspaces etc
		sc.convert(d);
	}
	sc.convert(av[1][0]);
	return 0;
}
