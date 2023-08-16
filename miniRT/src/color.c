#include "miniRT.h"

t_color	int_to_rgb(const int r, const int g, const int b)
{
	t_color	rgb;

	rgb.r = r;
	rgb.g = g;
	rgb.b = b;
	return (rgb);
}

t_color	char_to_rgb(const char *r, const char *g, const char *b)
{
	t_color rgb;

	rgb.r = ft_atoi(r);
	rgb.g = ft_atoi(g);
	rgb.b = ft_atoi(b);
	return (rgb);
}

int	rgb_to_int(t_color *rgb)
{
	int	rgb_int;
	
	rgb_int = 0;
	rgb_int = (rgb_int << 8) | rgb->r;
	rgb_int = (rgb_int << 8) | rgb->g;
	rgb_int = (rgb_int << 8) | rgb->b;
	return (rgb_int);
}

uint32_t	frgb_to_int(t_fcolor *frgb)
{
	t_color rgb;

	rgb.r = (int)(frgb->r * 255);
	rgb.g = (int)(frgb->g * 255) & 0xFF;
	rgb.b = (int)(frgb->b * 255) & 0xFF;
	return (rgb.r << 16 | rgb.g << 8 | rgb.b);
}

t_color	rgb_rgb_mult(const t_color *rgb1, const t_color *rgb2)
{
	return (int_to_rgb(rgb1->r * (rgb2->r / 255), rgb1->g * (rgb2->g / 255), rgb1->b * (rgb2->b / 255)));
}

t_color	rgb_double_mult(const t_color *rgb, const double mult)
{
	return (int_to_rgb(rgb->r * mult, rgb->g * mult, rgb->b * mult));
}

t_color	rgb_rgb_add(const t_color *rgb1, const t_color *rgb2)
{
	return (int_to_rgb(rgb1->r + rgb2->r, rgb1->g + rgb2->g, rgb1->b + rgb2->b));
}

int	ft_min_int(const int a, const int b)
{
	if (a < b)
		return (a);
	return (b);
}

void	min_rgb(t_color *rgb)
{
	rgb->r = ft_min_int(rgb->r, 255);
	rgb->g = ft_min_int(rgb->g, 255);
	rgb->b = ft_min_int(rgb->b, 255);
}
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