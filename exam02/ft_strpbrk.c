#include <stdio.h>
#include <stdlib.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int i = 0;

	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
	{
		i = 0;
		while (s2[i])
		{
			if (*s1 == s2[i])
			{
				// printf("%s", (char *)s1);
				return ((char *)s1);
			}
			i++;
		}
		s1++;
	}
	printf("%s", (char *)s1);
	return (0);
}

int	main(void)
{
	char *s1 = "abcdefghi";
	char *s2 = "ghi";

	ft_strpbrk(s1, s2);
	return (0);
}
