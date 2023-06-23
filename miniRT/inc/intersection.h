#ifndef INTERSECTION_H
# define INTERSECTION_H

typedef struct	s_inter
{
	t_ray		ray;
	float		t;
	void		*pShape;
	t_fcolor	frgb;
}				t_inter;

//-----Instanciation-----//
t_inter	inter_init();
t_inter	inter_cpy(t_inter *inter1);
t_inter	inter_cpy_ray(t_ray *ray1);

//-----Manipulations-----//
bool	intersected(t_inter *inter1);
t_vec	inter_position(t_inter *inter1);

//-----Operations-----//
void	inter_eq(t_inter *inter1, t_inter *inter2);

#endif