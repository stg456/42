#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (str[i])
	{
		res *= str_base;
		if (str[i] == '-')
			sign = -1;
		if (str[i] >= '0' && str[i] <= '9')
		{
			res += str[i] - '0';
		}
		else if (str[i] >= 'a' && str[i] <= 'f')
		{
			res += str[i] - 'a' + 10;
		}
		else if (str[i] >= 'A' && str[i] <= 'F')
		{
			res += str[i] - 'A' + 10;
		}
		i++;
	}
	return (sign * res);
}

int main()
{
	char str[] = "-110";
	printf("%d\n", ft_atoi_base(str, 16));
	return (0);
}