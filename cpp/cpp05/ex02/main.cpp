/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/13 11:33:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test1() {

        ShrubberyCreationForm	shrub("formulaire de création de Shrubbery");
		RobotomyRequestForm		robot("formulaire de robotomysation");
		PresidentialPardonForm	presid("formulaire de pardon présidentiel");
        Bureaucrat B1("Jim", 150);

    try {
        B1.signForm(shrub);
		B1.executeForm(shrub);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    // try {
    //     B1.signForm(robot);
	// 	B1.executeForm(robot);
    // }
    // catch(std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }
	// std::cout << std::endl;
    // try {
    //     B1.signForm(presid);
	// 	B1.executeForm(presid);
    // }
    // catch(std::exception &e) {
    //     std::cerr << e.what() << std::endl;
    // }
	// std::cout << std::endl;
}

int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();

	return 0;
}
