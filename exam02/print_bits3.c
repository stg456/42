#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	char c;

	while (i--)
	{
		c = ((octet >> i) & 1) + '0';
		write(1, &c, 1);
	}
}