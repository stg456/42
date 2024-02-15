/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 14:31:45 by stgerard          #+#    #+#             */
/*   Updated: 2023/01/16 15:16:40 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __UTILITY_H__
#define __UTILITY_H__

#include <cstring>

template <typename T>
inline const T & Mini(const T & a, const T & b)
{
	return a < b ? a : b;
}

inline const char * Mini(const char * s1, const char * s2)
{
	return strcmp(s1, s2) < 0 ? s1 : s2;
}

#endif