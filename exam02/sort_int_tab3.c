#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void sort_int_tab(int *tab, unsigned int size)
{
	int i = 0;
	int swap;

	while (i < (size - 1)) // le -1 a cause du '\0'
	{
		if (tab[i] > tab[i + 1])
		{
			swap = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = swap;
		}
		else
			i++;
	}
}