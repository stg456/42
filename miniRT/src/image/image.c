#include "miniRT.h"

static bool		in_shadow(t_data *d, t_inter inter, t_vec light)
{
	t_inter	shadow;

	shadow.ray.pos = vecs_multf(&inter.normal, 0.0001);
	shadow.ray.pos = vecs_add(&inter.pos, &shadow.ray.pos);
	shadow.ray.axe = normalized(vecs_sus(&light, &shadow.ray.pos));
	shadow.ray.tMAX = RAY_T_MAX;
	return (shapes_doesintersect(&d->shapes, &shadow));
}

// void	ray_trace(mlx_image_t *img, t_cam *cam, t_shape *shapes)
void	ray_trace(void *param)
{
	t_data		*d;
	int			x;
	int			y;
	t_ray		ray;
	t_inter		inter;
	uint32_t	curr_pixel;
	bool		visible;

	d = (t_data*)param;
	x = 0;
	y = 0;
	
	while ((uint32_t)x < d->img->width)
	{
		while ((uint32_t)y < d->img->height)
		{
			// toute cette section doit encore être complétée et adaptée
			ray = make_ray(&d->cam, vec2_init_fs(((2.0f * x) / d->img->width) - 1.0f, ((-2.0f * y) / d->img->height) + 1.0f));
			//curr_pixel = (void*)get_pixel(d.img, x, y); 
			inter = inter_cpy_ray(&ray);
			if (shapes_intersect(&d->shapes, &inter))
			{
				curr_pixel = color_prod(inter.rgb, color_scale(d->amb.rgb, d->amb.ratio));
				visible = !in_shadow(d, inter, d->lum.pos);
				curr_pixel = color_add(curr_pixel, visible * color_comp(&d->lum, inter));
				mlx_put_pixel(d->img, x, y, curr_pixel);
			}
			else
			{
				curr_pixel = 255;
				mlx_put_pixel(d->img, x, y, curr_pixel);
			}
			y++;
		}
		y = 0;
		x++;
	}
	if (mlx_image_to_window(d->env.mlx, d->img, 0, 0) < 0)
	{
		mlx_close_window(d->env.mlx);
		ft_error("Error\nimpossible to create image\n");

	}
}

// inutile pour l'instant, sera utile pour le bonus (sauvergarde de l'image)
uint32_t	*get_pixel(mlx_image_t *img, int x, int y)
{
	return ((uint32_t *)img->pixels + (img->width * x * y));
}

// void		save_img(mlx_image_t *img, char *filename)
