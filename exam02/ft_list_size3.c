typedef struct    s_list
{
    struct s_list *next;
    void          *data;
}                 t_list;

int	ft_list_size(t_list *begin_list)
{
	t_list *lst;
	int i = 1;

	lst = begin_list;
	while (lst->next)
	{
		lst->data = lst->next;
		i++;
	}
	return (i);
}

// pas bon