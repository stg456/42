#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i = 0;
	size_t j = 0;

	while (s[i] != '\0' && reject[j] != '\0')
	{
		if (reject[j] == s[i])
			return (i);
		else j++;
		i++;
	}
}

// pas encore bon