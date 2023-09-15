/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 16:11:17 by stgerard          #+#    #+#             */
/*   Updated: 2023/09/15 10:47:26 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

void test1() {
	Bureaucrat B3("Jack", 5);
	Intern someRandomIntern;
	Form * rrf;
	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	// if (rrf) {
		// B3.signForm(*rrf);
		// B3.executeForm(*rrf);
	// }
	delete rrf;
}

// void test2() {
// 	Bureaucrat B3("Jack", 5);
// 	Intern someRandomIntern;
// 	Form * rrf;
// 	rrf = someRandomIntern.makeForm("shrubbery request", "Bender");
// 	B3.signForm(*rrf);
// 	B3.executeForm(*rrf);
// 	delete rrf;
// }

// void test3() {
// 	Bureaucrat B3("Jack", 5);
// 	Intern someRandomIntern;
// 	Form * rrf;
// 	rrf = someRandomIntern.makeForm("presidential pardon request", "Bender");
// 	B3.signForm(*rrf);
// 	B3.executeForm(*rrf);
// 	delete rrf;
// }

// void test4() {
// 	Bureaucrat B3("Jack", 5);
// 	Intern someRandomIntern;
// 	Form * rrf;
// 	rrf = someRandomIntern.makeForm("bla bla request", "Bender");
// 	if (rrf) {
// 		B3.signForm(*rrf);
// 		B3.executeForm(*rrf);
// 	}
// 	delete rrf;
// }

int main() 
{
	std::cout << "___test1___" << std::endl;
	test1();
	// std::cout << "___test2___" << std::endl;
	// test2();
	// std::cout << "___test3___" << std::endl;
	// test3();
	// std::cout << "___test4___" << std::endl;
	// test4();

	return 0;
}
