
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int	res;
	int i;
	int sign;

	i = 0;
	res = 0;
	sign = 1;

	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	// printf("%d", res * sign);
	return (sign * res);
}

int main()
{
	const char	*str = "-95587";
	// printf("%s", str);
	//ft_atoi(str);
	printf("%d\n", ft_atoi(str));
	printf("%d\n", atoi(str));
	return (0);
}
// bizare