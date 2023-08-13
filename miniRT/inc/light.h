#ifndef LIGHT_H
# define LIGHT_H

typedef struct	s_amb
{
	int			nbA;
	float		ratio;
	t_color		rgb;
}				t_amb;

typedef struct	s_lum
{
	int			nbL;
	t_vec		pos;
	float		ratio;
	t_color		rgb;
}				t_lum;

#endif