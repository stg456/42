/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 10:24:23 by stgerard          #+#    #+#             */
/*   Updated: 2023/05/15 11:02:10 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

class Brain
{
public:
	Brain();
	Brain (const Brain &copy);
	Brain& operator = (const Brain &rhs);
	virtual ~Brain();

	std::string	ideas[100];
};

#endif