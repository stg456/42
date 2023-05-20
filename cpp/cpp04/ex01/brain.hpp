/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:02:12 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/20 17:23:31 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include "Animal.hpp"

class Brain
{
public:
	Brain();
	Brain (const Brain &copy);
	Brain& operator = (const Brain &rhs);
	~Brain();

	std::string	getIdeas(int i);
	// void	setIdea(std::string idea, int i);

private:
	std::string	_ideas[100];
};

#endif