#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
	int fd;
	char *line;
	int i;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
		return (1);
	i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("LINE %d: %s", i++, line);
		free(line);
	}
	close(fd);
	return (0);
}
