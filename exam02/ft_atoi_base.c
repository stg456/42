#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int 	i = 0;
	char	*ref = "0123456789abcdef";
	int		res;
	int		sign;

	while (*str)
	{
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		{
			i++;
		}
		if (str[i] == '+')
			i++;
		if (str[i] == '-')
		{
			sign *=-1;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = 
		}

	}
	return (sign * res);
}
// pas bon