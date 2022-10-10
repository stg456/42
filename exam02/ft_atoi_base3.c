#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>


int	ft_atoi_base(const char *str, int str_base)
{
	// (void)str_base;
	int sign = 1;
	int i = 0;
	int k = 0;
	long res = 0;
	char *s = "0123456789abcdef";

	if (str[i] == '-')
		sign *= -1;
	i++;
	while (str[i])
	{
		k = 0;
		while (str[i] != s[k])
		{
			k++;
			printf("k %d\n", k);
		}
		if (s[k] >= '0' && s[k] <= '9')
		{
			res += k * str_base - '0';
			printf("1 %ld\n", res);
		}
		else if ((s[k] >= 'a' && s[k] <= 'f') || (s[k] >= 'A' && s[k] <= 'F'))
		{
			res += k * str_base - '0';
			printf("2 %ld\n", res);
		}
		i++;
	}
	printf("tot %ld\n", res);
	return (sign * res);
}

int main()
{
	char *str = "ff";
	printf("%d\n", ft_atoi_base(str, 16));
	return (0);
}

// pas encore bon