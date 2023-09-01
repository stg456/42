#ifndef CYLINDRE_H
# define CYLINDRE_H

typedef struct	s_lum	t_lum;
typedef struct	s_cyl
{
	t_vec			pos;
	t_vec			axe;
	float			radius;
	float			height;
	int				rgb;
	struct s_cyl	*next;
}				t_cyl;

#endif