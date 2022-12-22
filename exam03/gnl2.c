#include <unistd.h> // read
#include <stdlib.h> // malloc, free

#define BUFFER_SIZE 500

char	*get_next_line(int fd)
{
	int		i = 0;
	int		rd = 0;
	char	*buf;
	char	c;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	i = 0;
	rd = read(fd, c, 1);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	while (rd > 0)
	{
		buf[i++] = c;
		if (c == '\n')
			break ;
		rd = read(fd, c, 1); // si buffer de 1
	}
	if (rd <= 0 && i == 0)
	{
		return (free(buf), NULL);
	}
	buf[i] = '\0';
	return (buf);
}

// pas encore