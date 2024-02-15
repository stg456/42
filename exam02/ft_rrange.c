#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int     *ft_rrange(int start, int end)
{
	int i = 0;
	int	*res;
	int n = end - start;

	if (start > end)
		return (ft_rrange(end, start));
	res = (int *)malloc(sizeof(int) * n + 1);
	if (res)
	{
		while (i <= n)
		{
			res[i] = start;
			write(1, &start, 1);
			start++;
			i++;
		}
	}
	return (res);
}

int main()
{
	int start = 0;
	int end = 3;
	ft_rrange(start, end);
	return (0);
}
// peut etre