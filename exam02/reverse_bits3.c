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

unsigned char	reverse_bits(unsigned char octet)
{
	return (((octet >> 0) & 1) << 7) | \
			(((octet >> 1) & 1) << 6) | \
			(((octet >> 2) & 1) << 5) | \
			(((octet >> 3) & 1) << 4) | \
			(((octet >> 4) & 1) << 3) | \
			(((octet >> 5) & 1) << 2) | \
			(((octet >> 6) & 1) << 1) | \
			(((octet >> 7) & 1) << 0);
}

int main(void)
{
	unsigned char octet = 38;

	print_bits(octet);
	write(1, "\n", 1);
	reverse_bits(octet);
	print_bits(reverse_bits(octet));
	return (0);
}

// bon

00100110
00000001
00000000
0 0000000			01______;
00100110
00010011
00000001
01000000
