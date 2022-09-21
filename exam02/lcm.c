#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

unsigned int    lcm(unsigned int a, unsigned int b)
{
	unsigned int	n = 2;

	if (a == 0 || b == 0)
		return (0);
	while (1)
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		n++;
	}
}

int main()
{
	printf("%d", lcm(3, 7));
	return 0;
}