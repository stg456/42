#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	int i = 1;
	t_list *lst;

	lst = begin_list;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// en fait non manque list == 0