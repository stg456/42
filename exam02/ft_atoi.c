int	ft_atoi(const char *str)
{
	int	res;
	int i;
	int sign;

	i = 0;
	res = 0;
	sign = 1;

	while (str[i])
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
		if (str[i] > '9')
		{
			str[i] / 10;
			str[i] % 10;
			res *= 10;
			i++;
		}
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = str[i] - '0';
		}
	}
	return (sign * res);
}
// pas encore bon