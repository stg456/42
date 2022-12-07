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

unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}

int main()
{
	unsigned char octet = 65;

	print_bits(octet);
	write(1, "\n", 1);
	swap_bits(octet);
	print_bits(swap_bits(octet));
	return (0);
}

// bon