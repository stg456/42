#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list *lst;

	lst->data = begin_list;
	while (lst->next)
	{
		(*f)(lst->data);
		lst = lst->next;
	}
	return (lst);
}

/// pas sur