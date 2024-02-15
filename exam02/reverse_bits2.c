#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int i = 8;
	unsigned char byte = 0;

	while (i--)
	{
		byte = byte * 2 + (octet % 2);
		octet /= 2;
	}
	return (byte);
}

int main()
{
	unsigned char c = 1;
	printf("%i\n", reverse_bits(c));
	return (0);
}