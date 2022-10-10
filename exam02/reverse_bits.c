#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

unsigned char	reverse_bits(unsigned char octet)
{
	int		i = 8;
	unsigned char	res = 0;

	while (i > 0)
	{
		res = res * 2 + (octet % 2);
		octet = octet / 2;
		i--;
	}
	return (res);
}

// int main(int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;

// 	unsigned char res;
// 	res = reverse_bits(00100110);
// 	// res = reverse_bits(av[1][0]);
// 	write(1, &res, 1);
// 	return (0);
// }

// pas bon pour le main et possible pour la fct

// int main()
// {
// 	unsigned char c = 40;
// 	printf("%i\n", reverse_bits(c));
// 	return (0);
// }