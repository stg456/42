#include <unistd.h> // read
#include <stdlib.h> // malloc, free

#define BUFFER_SIZE 500

char	*get_next_line(int fd)
{
	int		i;
	char	*buf;
	char	c;

	i = 0;
	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	buf = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	
}