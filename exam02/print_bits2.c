#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i = 7;
	char c;

	while (i >= 0)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
		i--;
	}
}

int main()
{
	unsigned char octet = 100;

	print_bits(octet);
	return (0);
}

// bon