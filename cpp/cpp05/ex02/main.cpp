/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/12 15:18:35 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test1() {
    try
    {
        ShrubberyCreationForm F1("form1");
        Bureaucrat B1("Jim", 5);
        Bureaucrat B2("Jess", 10);
        std::cout << B1;
        std::cout << B2;
        B1.signForm(F1);
        B2.executeForm(F1);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

// void test2() {
// 	try 
// 	{
// 		Bureaucrat B2("Joe", 60);
// 		Form F1("formulaire 1", 40, 60);
// 		std::cout << B1;
// 		std::cout << F1;

// 		B1.signForm(F1);

// 	}
// 	catch (std::exception &e) 
// 	{
// 		std::cerr << e.what() << std::endl;
// 	}
// }

int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();
	// std::cout << "___test2___" << std::endl;
	// test2();

	return 0;
}
