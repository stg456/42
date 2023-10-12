/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:15:37 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/12 12:25:48 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main() {
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	std::cout << "stack: ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;
	std::stack<int> s(mstack);

	std::cout << "____test en list____" << std::endl;

	std::list<int> inlist;
	inlist.push_back(5);
	inlist.push_back(17);
	std::cout << "top: " << inlist.back() << std::endl;
	inlist.pop_back();
	std::cout << "size: " << inlist.size() << std::endl;
	inlist.push_back(3);
	inlist.push_back(5);
	inlist.push_back(737);
	inlist.push_back(0);
	std::list<int>::iterator it2 = inlist.begin();
	std::list<int>::iterator ite2 = inlist.end();
	++it2;
	--it2;
	std::cout << "stack: ";
	while (it2 != ite2) {
		std::cout << *it2 << " ";
		++it2;
	}
	std::cout << std::endl;
	std::list<int> s2(inlist);

	return 0;
}