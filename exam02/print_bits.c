#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void	print_bits(unsigned char octet)
{
	int i = 8;
	unsigned char bits;

	while (i--)
	{
		bits = (octet >> i & 1) + '0';
		write(1, &bits, 1);
	}
}
// enfin bon
// faut pas mettre ' ' dans le main

int main()
{
	unsigned char c = 2;
	print_bits(c);
	return (0);
}