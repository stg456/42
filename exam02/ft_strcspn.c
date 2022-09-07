#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != reject[j])
		{
			while (s[i] != reject[j])
			{
				i++;
			}
		}
	}
}
// pas enore bon