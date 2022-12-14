#include <unistd.h>
#include <stdlib.h>

char *get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char c;
	char *buffer = malloc(500);

	while (rd = read(fd, &c, 1)> 0)
	{
		buffer[i++] = c;
		if (c == '\n')
			break;
	}
	if ((!buffer[i - 1] && !rd) || rd = -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}
