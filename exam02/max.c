

int		max(int* tab, unsigned int len)
{
	unsigned int	i = 0;
	int res = tab[i];
	
	while (i < len)
	{
		if (tab[i] > res)
		{
			res = tab[i];
		}
		i++;
	}
	return (res);
}

// enfin

int main()
{
	int tab[] = { 12, 45, 36, 78 };
	unsigned int len = 4;

	max(tab, len);
	return (0);
}