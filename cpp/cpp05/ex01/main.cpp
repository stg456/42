/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/08/13 15:54:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void test1() {
	try 
	{
		Bureaucrat B1("Jim", 10);
		Bureaucrat B2("Joe", 20);
		Form F1("formulaire 1", 4, 10);
		Form F2("formulaire 2", 20, 10);
		std::cout << B1;
		std::cout << B2;
		std::cout << F1;
		std::cout << F2;

		B1.signForm(F1);
		B1.signForm(F2);


	}
	catch (std::exception &e) 
	{
		std::cerr << e.what() << std::endl;
	}
}


int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();
	
	return 0;
}
