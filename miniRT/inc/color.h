#ifndef COLOR_H
# define COLOR_H

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_fcolor
{
	float		r;
	float		g;
	float		b;
}				t_fcolor;

t_fcolor	color_init(float r, float g, float b);

t_fcolor	color_initf(float f);

void		clamp(t_fcolor *frgb, float min, float max);

void		apply_gamma(t_fcolor *frgb, float exposure, float gamma);

t_color		int_to_rgb(const int r, const int g, const int b);

t_color		char_to_rgb(const char *r, const char *g, const char *b);

int			rgb_to_int(t_color *rgb);

uint32_t			frgb_to_int(t_fcolor *frgb);

int			ft_min_int(const int a, const int b);

t_color		rgb_rgb_mult(const t_color *rgb1, const t_color *rgb2);

t_color		rgb_double_mult(const t_color *rgb, const double mult);

t_color		rgb_rgb_add(const t_color *rgb1, const t_color *rgb2);

void		min_rgb(t_color *rgb);

void		frgb_eq(t_fcolor *frgb1, t_fcolor *frgb2);

void		rgb_eq(t_color *rgb1, t_color *rgb2);


// t_color		get_color(const char *type, const void *object);




#endif