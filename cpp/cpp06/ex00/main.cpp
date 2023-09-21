/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 09:49:57 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/21 17:16:08 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	ScalarConverter	sc;
	double			d = 0;

	if (argc != 2) {
		std::cout << "Wrong number of arguments" << std::endl;
		return 1;
	}
	if (argc == 2) {
		if (!sc.check(argv[1])) {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return 0;
		}
		if (strlen(argv[1]) == 1 && !isdigit(argv[1][0]))
			d = static_cast<double>(argv[1][0]);
		
		else {
			d = std::strtod(argv[1], NULL); // interprete comme un double, passe les whitspaces etc
			std::cout << "d: " << d << std::endl;
		}
	}
	sc.convert(d);
	
	return 0;
}
// pas encore les neg, pas encore le .0