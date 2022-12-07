#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i])
	{
		res *= str_base;
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - '0';
		else if (str[i] >= 'A' && str[i] <= 'F')
			res = res * 10 + str[i] - 'A' + 10;
		else if (str[i] >= 'a' && str[i] <= 'f')
			res = res * 10 + str[i] - 'a' + 10;
		i++;
	}
	return(sign * res);
}

int main()
{
	char *str = "-1Df0";

	printf("%d \n", ft_atoi_base(str, 16));
	return (0);
}