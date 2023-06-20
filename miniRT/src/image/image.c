#include "../../inc/image.h"
#include "../../inc/miniRT.h"

void	ray_trace(t_img *img, t_cam *cam, t_shape *shapes)
{
	int	x;
	int	y;
	t_vec2	screen_coord;
	t_ray	ray;
	t_inter	inter;
	float	*curr_pixel;

	x = 0;
	y = 0;
	while (x < img->width)
	{
		while (y < img->height)
		{
			// toute cette section doit encore être complétée et adaptée
			screen_coord = vec2_init_fs((2.0f * x) / img->width - 1.0f, (-2.0f * y) / img->height + 1.0f);
			ray = make_ray(screen_coord);
			curr_pixel = get_pixel(img, x, y);
			inter = inter_init(ray);
			if (intersect(inter))
			{
				*curr_pixel = 1.0f;
			}
			else
			{
				*curr_pixel = 0.0f;
			}
			y++;
		}
		x++;
	}
}
