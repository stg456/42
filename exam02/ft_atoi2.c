#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int i = 0;
	int sign = 1;
	int res = 0;

	while (str[i])
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
				sign *= -1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = res * 10 + str[i] - '0';
			// write(1, &res, 1);
			i++;
		}
	}
	return (sign * res);
}
int main()
{
	char *str = "-2147483648";

	printf("%d \n", atoi(str));
	printf(" le tien = %d \n", ft_atoi(str));
	printf("%d \n", atoi(str));
	return (0);
}

// bon
