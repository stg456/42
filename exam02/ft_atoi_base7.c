#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int res;
	int sign = 1;

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		res *= str_base;
		if (*str >= '0' && str[i] <= '9')
			res += str[i] - '0';
		else if (*str >= 'a' && str[i] <= 'f')
			res += str[i] - 'a' + 10;
		else if (*str >= 'A' && str[i] <= 'F')
			res += str[i] - 'A' + 10;
		i++;
	}
	return (sign * res);
}

int main(void)
{
	const char *str = "ff";

	printf("%d \n", ft_atoi_base(str, 16));
	return 0;
}