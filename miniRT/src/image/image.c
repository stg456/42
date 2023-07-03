#include "miniRT.h"

// void	ray_trace(mlx_image_t *img, t_cam *cam, t_shape *shapes)
void	ray_trace(void *param)
{
	t_data		d;
	int			x;
	int			y;
	t_vec2		screen_coord;
	t_ray		ray;
	t_inter		inter;
	t_fcolor	curr_pixel;

	d = *(t_data*)param;
	x = 0;
	y = 0;
	
	while ((uint32_t)x < d.img->width)
	{
		while ((uint32_t)y < d.img->height)
		{
			// toute cette section doit encore être complétée et adaptée
			screen_coord = vec2_init_fs((2.0f * x) / d.img->width - 1.0f, (-2.0f * y) / d.img->height + 1.0f);
			// printf("BEFORE MAKE RAY\n");
			ray = make_ray(&d.cam, screen_coord);
			// curr_pixel = (void*)get_pixel(img, x, y); 
			// printf("BEFORE INTER\n");
			inter = inter_cpy_ray(&ray);
			// printf("BEFORE SHAPES_INTERSECT\n");
			if (shapes_intersect(&d.shapes, &inter))
			{
				// printf("BEFORE MLX_PUT_PIXEL\n");
				mlx_put_pixel(d.img, x, y, 999999999);
			}
			else
			{
				// printf("BEFORE MLX_PUT_PIXEL\n");
				curr_pixel = color_init(0.0f, 0.0f, 0.0f);
				mlx_put_pixel(d.img, x, y, frgb_to_int(&curr_pixel));
			}
			y++;
		}
		y = 0;
		x++;
	}
	
	// while ((uint32_t)x < d.img->width)
	// {
	// 	while ((uint32_t)y < d.img->height)
	// 	{
	// 		//curr_pixel = color_initf(0.0f);
	// 		mlx_put_pixel(d.img, x, y, 456321789);
	// 		y++;
	// 	}
	// 	y = 0;
	// 	x++;
	// }
}

uint8_t	*get_pixel(mlx_image_t *img, int x, int y)
{
	return img->pixels + (img->width * x * y);
}

// void		save_img(mlx_image_t *img, char *filename)
// {
// 	printf("dans save_img");
// }