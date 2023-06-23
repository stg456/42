#ifndef DATA_H
# define DATA_H

typedef struct	s_data
{
	int			fd;
	int			nbA;
	int			nbC;
	int			nbL;
	int			nbsp;
	int			nbpl;
	int			nbcy;
	mlx_image_t	*img;
	t_cam		cam;
	t_shape		shapes;
	t_amb		amb;
	t_lum		lum;
	t_env		env; // ajouté pour pouvoir avoir accès à la résolution pour l'init de la camera
}				t_data;

#endif