/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/13 15:50:15 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

void test() {

        ShrubberyCreationForm	shrub("formulaire de création de Shrubbery");
		RobotomyRequestForm		robot("formulaire de robotomysation");
		PresidentialPardonForm	presid("formulaire de pardon présidentiel");
        Bureaucrat B1("Jim", 130);
		Bureaucrat B2("Jess", 50);
		Bureaucrat B3("Jack", 10);

    try {
        B1.signForm(shrub);
		B1.executeForm(shrub);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B2.signForm(robot);
		B2.executeForm(robot);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
    try {
        B3.signForm(presid);
		B3.executeForm(presid);
    }
    catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
	std::cout << std::endl;
}

int main() 
{
	std::cout << "___test___" << std::endl;
	test();

	return 0;
}
