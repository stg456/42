#include "miniRT.h"

void	keyhook(mlx_key_data_t keydata, void *param)
{
	t_env	*e;

	e = (t_env *)param;
	if (keydata.key == MLX_KEY_ESCAPE)
		close_hook(*e);
	// else if (keydata.key == MLX_KEY_S)
	// 	save_img(d.img, av[1]);
	// else if (keydata.key == MLX_KEY_SPACE)
	// 	action(keydata.key, e);
	return ;
}

int		close_hook(t_env e) // to be reworked
{
	(void)e;
	// free(&e);
	exit(EXIT_SUCCESS);
}

void	expose_hook(void *param)
{
	t_data *d;
	d = param;
	if (mlx_image_to_window(d->env.mlx, d->img, 0, 0) < 0)
	{
		mlx_close_window(d->env.mlx);
		ft_error("Error\nimpossible to create image\n");

	}
}

void	mlx_loops(t_data *d)
{
	mlx_key_hook(d->env.mlx, &keyhook, &d->env);
	mlx_loop_hook(d->env.mlx, &expose_hook, d);
	mlx_loop(d->env.mlx);
}