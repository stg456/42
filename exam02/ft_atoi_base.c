#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_contains(char c, int str_base)
{
	int i = 0;
	char *s = "0123456789abcdef";
	while (s[i] && i < str_base)
	{
		if (c == s[i] || c == s[i] -32)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi_base(const char *str, int str_base)
{
	int 	i = 0;
	long	res = 0;
	int		sign = 1;
	// char *s = "0123456789abcdef";

	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	while (str[i] && ft_contains(str[i], str_base))
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	return (sign * res);
}
// pas bon

int main()
{
	const char	*str = "1ff";
	printf("%d\n", ft_atoi_base(str, 10));
	// printf("%d\n", atoi(str));
	return (0);
}