#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(const char *str, int str_base)
{
	int	idx;
	int	sign;
	int	result;

	idx = 0;
	sign = 1;
	result = 0;
	if (str[idx] == '-')
	{
		sign = -1;
		idx++;
	}
	while (str[idx] != '\0')
	{
		result *= str_base; // base de depart
		if (str[idx] >= '0' && str[idx] <= '9')
			result += str[idx] - '0';
		else if (str[idx] >= 'A' && str[idx] <= 'Z')
			result += str[idx] - 'A' + 10; // base result
		else if (str[idx] >= 'a' && str[idx] <= 'z')
			result += str[idx] - 'a' + 10; // base result
		idx++;
	}
	return (result * sign);
}

int main()
{
	char *str = "D1f0";
	printf("%d\n", ft_atoi_base(str, 16)); // base de depart
	return (0);
}