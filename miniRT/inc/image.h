#ifndef IMAGE_H
# define IMAGE_H

uint8_t		*get_pixel(mlx_image_t *img, int x, int y);

void		save_img(mlx_image_t *img, char *filename);

void		ray_trace(void *param);

#endif