#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int 	i = 0;
	int		res = 0;
	int		sign = 1;


	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] != '\0')
	{

		if (str[i] > str_base - '0')
		{
			res = str[i] / str_base;
			// write(1, &str[i % str_base], 1);
		}
		write(1, &str[i % str_base], 1);
		i++;
		// res = res * str_base;
		// if (str[i] >= '0' && str[i] <= '9')
		// 	res += str[i] - '0';
		// else if (str[i] >= 'a' && str[i] <= 'f')
		// 	res += str[i] - 'a' + 10;
		// else if (str[i] >= 'A' && str[i] <= 'F')
		// {
		// 	res += str[i] - 'A' + 10;
		// }
		// i++;
	}
	return (sign * res);
}
// pas bon

int main()
{
	const char	*str = "ff";
	printf("%d\n", ft_atoi_base(str, 10));
	// printf("%d\n", atoi(str));
	return (0);
}