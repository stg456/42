#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct      s_list
{
    struct s_list   *next;
    void            *data;
}                   t_list;

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list *lst;

	lst = begin_list;
	while (lst->next)
	{
		if ((*cmp)(lst->data, *data_ref) == 0)
		{

		}
	}
}

// loin d'y etre  