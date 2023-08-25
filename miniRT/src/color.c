#include "miniRT.h"

// int	rgb_to_int(t_color *rgb)
// {
// 	// int	rgb_int;
	
// 	// rgb_int = 0;
// 	// rgb_int = (rgb_int << 8) | rgb->r;
// 	// rgb_int = (rgb_int << 8) | rgb->g;
// 	// rgb_int = (rgb_int << 8) | rgb->b;
// 	return ((rgb->r << 0x10) | (rgb->g << 0x08) | rgb->b);
// }

int	ft_min_int(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}

// void	min_rgb(t_color *rgb)
// {
// 	rgb->r = ft_min_int(rgb->r, 255);
// 	rgb->g = ft_min_int(rgb->g, 255);
// 	rgb->b = ft_min_int(rgb->b, 255);
// }
/*
t_color	get_color(const char *type, const void *object)
{
	if (!ft_strncmp(type, "sp", ft_strlen(type)))
		return ((t_sphere*)object)->rgb;
	if (!ft_strncmp(type, "pl", ft_strlen(type)))
		return ((t_plane*)object)->rgb;
	if (!ft_strncmp(type, "cyl", ft_strlen(type)))
		return ((t_cyl*)object)->rgb;
	return (NULL);
}
*/