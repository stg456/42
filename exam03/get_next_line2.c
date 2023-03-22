#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

char *get_next_line(int fd)
{
	int i = 0;
	int rd = 0;
	char c;
	char *buf = malloc(10000);

	if (BUFFER_SIZE <= 0)
	{
		free(buf);
		return (NULL);
	}
	while ((rd = read(fd, &c, BUFFER_SIZE - BUFFER_SIZE + 1)) > 0)
	{
		buf[i++] = c;
		if (buf[i] == '\n')
			break ;
		if (rd == -1 || (!rd && !buf[i - 1]))
		{
			free(buf);
			return (NULL);
		}
	}
	buf[i] = '\0';
	return (buf);
}
