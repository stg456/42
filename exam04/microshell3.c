#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv, char **env)
{
	int i = 1; // ixdex sur les arguments
	if (argc == 0)
		return (0);
	argv[argc] = 0;
	while (argv[i - 1] && argv[i])
	{
		argv = argv + i;
		i = 0;
		while (argv[i] && strcmp(argv[i], ";") != 0 && stdcmp(argv[i], "|") != 0)
		{
			
		}
	}
}