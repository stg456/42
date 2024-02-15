#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *src)
{
	int	i = 0;
	while (src[i])
		i++;
	return (i);
}

char    *ft_strdup(char *src)
{
	int	i;
	char	*dest;

	i = 0;
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	// printf("%s", dest);
	return (dest);
}

// int main(void)
// {
// 	char	*src = "abcdefghi";
// 	ft_strdup(src);
// 	return (0);
// }
