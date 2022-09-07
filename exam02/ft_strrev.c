#include <stdio.h>

char    *ft_strrev(char *str)
{
	int		i = 0;
	int		j = -1;
	char	tmp;

	while (str[i])
	{
		i++;
	}
	// printf("2%s\n", str);
	// printf("%i\n", i);
	// printf("%i\n", j);
	while (i > j)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		printf("3 %s\n", str);
		i--;
		j++;

	}
	printf("4 %s \n", str);
	return (str);
}

// enfin

int main(void)
{
	char str[] = "abcdefghi";
	printf("1 %s\n", str);
	ft_strrev(str);
	printf("5 %s\n", str);
	return (0);
}