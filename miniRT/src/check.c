/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stgerard <stgerard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 17:44:25 by stgerard          #+#    #+#             */
/*   Updated: 2023/06/08 15:31:19 by stgerard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	check(t_env e, int ac, char **av)
{
	(void)e;
	if (ac != 2)
		ft_error("\x1B[31mError\nBad number of arguments\n");
	if (ft_strnstr(av[1], ".rt", ft_strlen(av[1])) == NULL)
		ft_error("\x1B[31mError\nmap has to be .rt\n");
}

int	rgbinrange(int nb)
{
	if (nb < 0 || nb > 255)
		ft_error("Error\nincorrect color\n");
	return (0);
}

int	vectinrange(double nb)
{
	if (nb < -1 || nb > 1)
		ft_error("Error\nincorect vector\n");
	return (0);
}

int	ratioinrange(double nb)
{
	if (nb < 0 || nb > 1)
		ft_error("Error\nincorect ratio\n");
	return (0);
}
