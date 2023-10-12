/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:27:21 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/12 11:40:42 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
// # include <deque>
// # include <vector>
// # include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack() : std::stack<T>() {};
		MutantStack(const MutantStack& copy) : std::stack<T>(copy) {};
		~MutantStack() {};
		MutantStack& operator = (const MutantStack& rhs) {
			this->c = rhs.c;
			return *this;
		};

		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {
			return this->c.begin();
		};
		iterator end() {
			return this->c.end();
		};
};

#endif