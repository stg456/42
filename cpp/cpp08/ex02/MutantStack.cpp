/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 17:31:14 by stgerard          #+#    #+#             */
/*   Updated: 2023/10/12 11:13:41 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

MutantStack::MutantStack() : std::stack() {}

MutantStack::MutantStack(const MutantStack& copy) : std::stack(copy) {}

MutantStack::~MutantStack() {}

