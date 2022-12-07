#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int     *ft_range(int start, int end)
{
	int	*tmp;
	int	len = 0;

	if (end > start)
		len = end - start;
	else if (start > end)
		len = start - end;
	tmp = malloc(sizeof(int) * len + 1);
	if (tmp == NULL)
		return (NULL);
	while (len >= 0)
	{
		tmp[len] = end;
		if (start > end)
			end++;
		else
			end--;
		len--;
	}
	return (tmp);
}

// int	main(void)
// {
// 	ft_range(1, 3);
// 	return (0);
// }

// pas sur